-- create database invoicing;

use invoicing;

-- drop table payments;
-- drop table payment_methods;
-- drop table clients;
-- drop table invoices;

create table payment_methods(
    id int not null auto_increment primary key,
    name nvarchar(50) not null
)engine=InnoDB default charset=utf8mb4;

create table clients(
    id int not null primary key,
    name nvarchar(50) not null,
    address nvarchar(50) not null,
    city nvarchar(50) not null,
    state nvarchar(50) not null,
    phone nvarchar(50) default null
)engine=InnoDB default charset=utf8mb4;

create table invoices(
    id int not null primary key,
    number nvarchar(50) not null,
    client_id int not null,
    invoice_total double not null,
    payment_total double not null,
    invoice_date nvarchar(50),
    due_date nvarchar(50),
    payment_date nvarchar(50)
)engine=InnoDB default charset=utf8mb4;

create table payments(
    id int not null auto_increment primary key,
    client_id int not null,
    invoice_id int not null,
    date nvarchar(50) not null,
    amount double not null,
    payment_method int not null,
    foreign key (client_id) references clients(id),
    foreign key (invoice_id) references invoices(id),
    foreign key (payment_method) references payment_methods(id)
)engine=InnoDB default charset=utf8mb4;