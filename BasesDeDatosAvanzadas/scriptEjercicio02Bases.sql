-- create database store;

use store;

drop table if exists products;
drop table if exists shippers;
drop table if exists customers;
drop table if exists order_statuses;

create table products(
    id int not null auto_increment primary key,
    name varchar(50) not null,
    quantity_in_stock int not null,
    unit_price double not null
)engine=InnoDB default charset=utf8mb4;

create table shippers(
    id int auto_increment primary key,
    name varchar(50) not null
)engine=InnoDB default charset=utf8mb4;

create table customers(
    id int auto_increment  primary key,
    first_name varchar(50) not null,
    last_name varchar(50) not null,
    birth_date varchar(50) not null,
    phone varchar(50) default null,
    adress varchar(50) not null,
    city varchar(50) not null,
    state varchar(50) not null,
    points int default 0
)engine=InnoDB default charset=utf8mb4;

create table order_statuses(
    id int not null,
    name varchar(100) primary key
)engine=InnoDB default charset=utf8mb4;