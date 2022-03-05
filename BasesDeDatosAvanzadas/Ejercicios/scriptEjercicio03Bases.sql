-- create database store;

use store;

drop table  if exists order_items;
drop table if exists orders;
drop table if exists order_item_notes;

SET FOREIGN_KEY_CHECKS=0;

create table order_item_notes(
    note_id int not null auto_increment primary key,
    order_Id varchar(50),
    product_id varchar(50),
    note varchar(50)
)engine=InnoDB default charset=utf8mb4;

create table orders(
    id int auto_increment primary key,
    customer_id int,
    order_date varchar(100),
    statuses varchar(100),
    comments varchar(100),
    shipped_date varchar(100),
    shipper_id int,
    foreign key (customer_id) references customers(id) ON UPDATE CASCADE,
    foreign key (statuses) references order_statuses(name) ON UPDATE CASCADE,
    foreign key (shipper_id) references shippers(id) on UPDATE CASCADE 
)engine=InnoDB default charset=utf8mb4;

create table order_items(
	id int not null, -- auto_increment, -- primary key,
	quantity int,
	product_id int,
	unit_price double,
    foreign key (product_id) references order_item_notes(note_id) ON UPDATE CASCADE 
)engine=InnoDB default charset=utf8mb4;
