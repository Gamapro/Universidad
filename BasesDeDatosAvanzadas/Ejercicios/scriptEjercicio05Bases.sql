-- create database inventory;

use inventory;

drop table if exists products;

create table products(
    id int not null auto_increment primary key,
    name varchar(50),
	quantity_in_stock int,
	unit_price int
)engine=InnoDB default charset=utf8mb4;
