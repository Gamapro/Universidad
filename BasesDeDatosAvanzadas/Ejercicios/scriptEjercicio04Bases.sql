-- create database hr;

use hr;

drop table if exists employees;
drop table if exists offices;

create table offices(
    id int not null primary key,
    address varchar(100),
    city varchar(100),
    state varchar(100)
)engine=InnoDB default charset=utf8mb4;

create table employees(
    id int not null auto_increment primary key,
    first_name varchar(50),
    last_name varchar(50),
    job_tittle varchar(50),
    salary int,
    reports_to int,
    office_id int,
    foreign key (office_id) references offices(id)
)engine=InnoDB default charset=utf8mb4;
