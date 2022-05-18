use f1_database;

-- Final Project Advanced Databases
-- F1 Statistics Database
-- By David Gamaliel Arcos Bravo

-- Selects-if		- 3 -
-- View 			- 6 -
-- Store Procedure 	- 3 -
-- Functions 		- 3 -
-- Triggers			- 3 -
-- Events 			- 3 -
-- Transactions 	- 4 -

-- ----------------------------------------  SELECTS  ---------------------------------------- --

-- 1.- Select all the podiums from every team, and separate by first second ad third places

select name,nationality,
count(1) podium, if(position=1,"Wins",if(position=2,"Second places","Third places")) as podiumPosition from results rs
join constructors c on rs.constructorId=c.constructorId
where position < 4 and concat('',position * 1) = position
group by position, name
order by name, position;

-- 2.- Select all the podiums from every driver, and separate by first second ad third places

select concat(forename,' ',surname) as name, nationality,
count(1) podium, if(position=1,"Wins",if(position=2,"Second places","Third places")) as podiumPosition from results rs
join drivers d on d.driverId = rs.driverId
where position < 4 and concat('',position * 1) = position
group by position, name
order by name, position;

-- 3.- Select all the circuits and count the number of races on that circuit.
-- 	   Then check if that track it's a classic track
--     It is if it has held more than 10 races

select c.name, c.location, c.country, count(1) as 'No. of races',
if(count(1) > 10, "Yes", "No") as classicTrack
from races r
join circuits c on c.circuitId=r.circuitId
group by c.name;

-- ----------------------------------------  VIEWS  ---------------------------------------- --

-- 1.- Get view with drivers total scored points

create or replace view drivers_scored_points as
select d.driverId,concat(forename,' ',surname) as name,nationality,d.number,code,driverRef, dob dateOfBirth, sum(points) totalPoints, count(r.driverId) as 'Number of races' from results r
join drivers d on r.driverId=d.driverId
group by d.driverId
order by totalPoints desc;

-- 2.- Get view with fastest lap for each circuit

create or replace view circuits_fastest_lap as
select c.circuitId,c.name as 'Circuit Name', c.circuitRef, rc.name, country, location, min(fastestLapTime) as fastestLapTime from results r
join races rc on rc.raceId=r.raceId
join circuits c on rc.circuitId=c.circuitId
where r.time!='N' and fastestLapTime!='N'
group by c.name
order by country;

-- 3.- Get view with pitstops duration for each race on each lap

create or replace view pitstops_duration_for_circuit as
select c.circuitId,c.name as 'Circuit Name', c.circuitRef, rc.name, country, location, 
p.lap, min(p.duration) as minDuration, max(p.duration) as maxDuration, avg(p.duration) as averageDuration from pitstops p
join races rc on rc.raceId=p.raceId
join circuits c on rc.circuitId=c.circuitId
group by c.circuitId, p.lap;

-- 4.- Get view with constructors wins
create or replace view constructors_wins as
select c.constructorId, c.name,c.nationality,c.constructorRef,count(1) as wins from results r
join constructors c on r.constructorId=c.constructorId
where position=1
group by c.name
order by wins desc;

-- 5.- Get view with constructors points
create or replace view constructors_points as
select c.constructorId, c.name,c.nationality,c.constructorRef,cw.wins, sum(points) as totalPoints from results r
join constructors c on c.constructorId=r.constructorId
join constructors_wins cw on cw.constructorId=r.constructorId
group by r.constructorId;

-- 6.- Get view with constructors total races
create or replace view constructors_statistics as
select c.constructorId, c.name,c.nationality,c.constructorRef,wins,totalPoints, count(distinct raceId) as 'No. of races' from results r
join constructors_points c on c.constructorId=r.constructorId
group by r.constructorId;

-- ----------------------------------------  STORE PROCEDURE  ---------------------------------------- --

-- 1.- Get count of drivers final positions, determined by driver's reference name

drop procedure if exists get_driver_results;
DELIMITER $$
create procedure get_driver_results(driver varchar(25))
begin
	select d.driverId, concat(forename,' ',surname) as name, nationality, d.driverRef, points, position, count(1) as count from results r
	join drivers d on r.driverId=d.driverId
	where d.driverRef=driver
	group by position
	order by positionOrder asc;
end$$
DELIMITER ;
call get_driver_results('hamilton');
call get_driver_results('perez');

-- 2.- Get races per year, determined by referenced year

drop procedure if exists get_races_per_year;
DELIMITER $$
create procedure get_races_per_year(year_ int)
begin
	select * from races
    where year=year_
    order by round asc;
end$$
DELIMITER ;
call get_races_per_year(2009);
call get_races_per_year(2021);

-- 3.- Get driver total scored point

drop procedure if exists get_driver_scored_points;
DELIMITER $$
create procedure get_driver_scored_points(driver varchar(30))
begin
	select * from drivers_scored_points
    where driverRef=driver;
end$$
DELIMITER ;
call get_driver_scored_points('verstappen');
call get_driver_scored_points('alonso');
call get_driver_scored_points('sainz');
call get_driver_scored_points('vettel');
call get_driver_scored_points('perez');

-- ----------------------------------------  FUNCTIONS  ---------------------------------------- --

-- ------------------ IMPORTANT ------------------ --
-- Functions tend to be way slower than normal select

-- 1.- Get percentage of wins for each constructor

DELIMITER $$
drop function if exists get_wins_percentage_for_constructor;
create function get_wins_percentage_for_constructor(constructor varchar(20))
returns decimal
reads sql data
begin
    declare _res decimal(5,2) default 1.00;
	select ((wins/`No. of races`)*100.0) into _res from constructors_statistics cs
    where constructorRef=constructor;
    return ifnull(_res,0.0);
end $$
DELIMITER ;
select name, concat(get_wins_percentage_for_constructor(`constructorRef`),'%') as percentageOfWins from constructors;

-- 2.- Get average points for race for each constructor

DELIMITER $$
drop function if exists get_points_average_for_constructor;
create function get_points_average_for_constructor(constructor varchar(20))
returns decimal
reads sql data
begin
    declare _count int;
    declare _total int;
    declare _res decimal(4,2) default 1.0;
	select `totalPoints`,`No. of races` into _count, _total from constructors_statistics c
	where c.constructorRef=constructor;
    set _res = ((_count)/_total);
    return ifnull(_res,0.0);
end $$
DELIMITER ;
select name, get_points_average_for_constructor(`constructorRef`) as averageOfPoints from constructors;

-- 3.- Get average points for each driver

DELIMITER $$
drop function if exists get_average_driver_points;
create function get_average_driver_points(driver varchar(20))
returns decimal
reads sql data
begin
    declare _count int;
    declare _total int;
    declare _res decimal(4,2) default 1.0;
	select totalPoints,`Number of races` into _count, _total from drivers_scored_points
    where driverRef=driver;
    set _res = ((_count)/_total);
    return ifnull(_res,0.0);
end $$
DELIMITER ;
select concat(forename,' ',surname) as name, get_average_driver_points(`driverRef`) as averageOfPoints from drivers
order by averageOfPoints desc;

-- ----------------------------------------  TRIGGERS  ---------------------------------------- --

-- 1.- Update total points of each driver after new races resuts are added

drop trigger if exists update_drivers_points
DELIMITER $$
create trigger update_drivers_points
after insert on results
for each row 
begin 
	update drivers_scored_points 
    set totalPoints= totalPoints+points
    where driverId=new.driverId;
end $$
DELIMITER ;

-- 2.- Update circuits fastests laps after new races resuts are added

drop trigger if exists update_circuits_fastest_lap
DELIMITER $$
create trigger update_circuits_fastest_lap
after insert on results
for each row
begin 
	declare circuit int;
	set circuit = (select r.circuitId from results rs
		join races r on r.raceId=rs.raceId
		where rs.raceId=new.raceId
    );
	update circuits_fastest_lap c
    set fastestLapTime = min(fastestLapTime)
    where c.circuitId=circuit;
end $$
DELIMITER ;

-- 3.- Update circuits fastests laps after new races resuts are added

drop trigger if exists update_pitstops_duration
DELIMITER $$
create trigger update_pitstops_duration
after insert on pitstops
for each row
begin 
	declare circuit int;
	set circuit = (select r.circuitId from pitstops p
		join races r on p.raceId=r.raceId
		where r.raceId=new.raceId
    );
	update pitstops_duration_for_circuit pd
    set minDuration = min(fastestLapTime),
	maxDuration = max(fastestLapTime),
	avgDuration = avg(fastestLapTime)
    where pd.circuitId=circuit;
end $$
DELIMITER ;

-- ----------------------------------------  EVENTS  ---------------------------------------- --

-- 1.- Event to keeping updated Checo Perez results to know if he has win a race

drop event if exists check_perez_results;
create event if not exists check_perez_results
on schedule every 1 week 
ends current_timestamp + interval 1 year
DO
	call get_driver_results('perez');

-- 2.- Event to keeping updated Red Bull Racing podiums

drop event if exists check_redbull_podiums;
create event if not exists check_redbull_podiums
on schedule every 1 month 
ends current_timestamp + interval 2 year
DO
	select c.name,nationality,c.constructorRef,cr.name, cr.circuitRef,
	count(1) podium, if(position=1,"Wins",if(position=2,"Second places","Third places")) as podiumPosition from results r
    join constructors c on c.constructorId=r.constructorId
    join races rc on r.raceId=rc.raceId
    join circuits cr on cr.circuitId=rc.circuitId
    where c.constructorRef='red_bull' and position < 4 and concat('',position * 1) = position
    group by position, circuitRef
    order by position;

-- 3.- Event to get this year races

drop event if exists get_races_on_this_year;
create event if not exists get_races_on_this_year
on schedule every 3 month 
ends current_timestamp + interval 5 year
DO
	select year,r.name,r.date,r.time,r.round,c.name, c.circuitRef, c.location, c.country from races r
    join circuits c on c.circuitId=r.circuitId
    where r.year = year(curdate());
    
-- ----------------------------------------  TRANSACTIONS  ---------------------------------------- --

-- -------------------------- Create table for new transactions examples -------------------------- -- 

drop table if exists new_drivers;
create table new_drivers(id int primary key auto_increment, name varchar(20),age int);

-- 1.- Read uncommitted
-- This options has the problem of reading transactions that can be later rolled back
-- This can lead to read worng data, to get last updates or not reliable information

set autocommit = OFF;
set transaction isolation level read uncommitted;
start transaction; 
insert into new_drivers (name, age) values ('Gama',20);
insert into new_drivers (name, age) values ('El bicho',38);
insert into new_drivers (name, age) values ('Checo perez jr',2);
insert into new_drivers (name, age) values ('San Pedro',2050);
commit;

-- 2.- Read committed
-- With this option we take out the problem of reading uncommited data.
-- Nevertheless, we are still haaving problems whit late updates

set autocommit = OFF;
set transaction isolation level read committed;
start transaction; 
insert into new_drivers (name, age) values ('Cris',21);
update new_drivers
set age = 20
where id=5;
commit;
rollback;

-- 3.- Repeatable read
-- This options eliminates the problem of dirty read, but also solves a big problem with updates.
-- Selecting repeatable read assures that the data you are reading to cannot change.
-- Whenever you read the data under the transaction it will be still the same.

set autocommit = OFF;
set transaction isolation level repeatable read;
select * from new_drivers where age = 20;
insert into new_drivers (name, age) values ('Sebas',32);
insert into new_drivers (name, age) values ('Fabio',24);
insert into new_drivers (name, age) values ('Fabio',26);
update new_drivers
set age = 20
where name='Fabio';
select * from new_drivers where age = 20;
commit;


-- 4.- Serializable
-- The strongest options, as it, in addtition to solving the problems previously mentioned,
-- guarantees that no new data can be seen by a subsequent read. 
-- This helps to keep all the orginial data withouth modifications.

set autocommit = OFF;
set transaction isolation level serializable;
select * from new_drivers where age = 20;
insert into new_drivers (name, age) values ('Sebas',32);
insert into new_drivers (name, age) values ('Soteldo',20);
insert into new_drivers (name, age) values ('Pedro',20);
insert into new_drivers (name, age) values ('Chavez',12);
select * from new_drivers where age = 20;
update new_drivers
set age = 20
where id=6;
select * from new_drivers where age = 20;
commit;

