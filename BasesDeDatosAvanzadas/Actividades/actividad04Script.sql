use store;

create table customers_back as select * from customers;
create table orders_back as select * from orders;
create table order_items_back as select * from order_items;

insert into customers_back 
select * from customers c
where c.id not in (select id from customers_back);


use invoicing;

create table clients_back as select * from clients;
create table INVOICES_ARCHIVED as select c.id, c.name from clients c;

insert into clients_back 
select * from clients c
where c.id not in (select id from INVOICES_ARCHIVED);

