-- create database hr;

use hr;

drop table if exists offices;
drop table if exists employees;

create table offices(
    id int not null primary key,
    address varchar(50),
    city varchar(50),
    state varchar(50)
)engine=InnoDB default charset=utf8mb4;

create table employees(
    id int not null auto_increment primary key,
    first_name varchar(50),
    last_name varchar(50),
    job_tittle varchar(50),
    salary double,
    reports_to varchar(50),
    office_id int,
    foreign key (office_id) references offices(id)
)engine=InnoDB default charset=utf8mb4;
