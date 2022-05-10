
use invoicing;

DELIMITER $$

create trigger payments_after_insert
after insert on payments
for each row 
begin 
	update invoices
	set payment_total = payment_total + new.amount
	where invoice.id = new.invoice.id;
end $$
    
DELIMITER ;

-- trigger payment eliminado 

DELIMITER $$
create trigger payments_after_delete
before delete on payments
for each row 
begin 
	update invoices
	set payment_total = payment_total - old.amount
	where invoice.id = old.invoice.id;
end $$
DELIMITER ;

-- backups

use store;

create table if not exists customers_archived like customers;
create table if not exists order_items_archived like order_items;
create table if not exists orders_archived like orders;

DELIMITER $$
create trigger customers_trigger
before delete on customers
for each row 
begin 
	insert into customers_archived values (old);
end $$
DELIMITER ;
DELIMITER $$
create trigger orders_trigger
before delete on orders
for each row 
begin 
	insert into customers_archived values (old);
end $$
DELIMITER ;
DELIMITER $$
create trigger order_items_trigger
before delete on order_items
for each row 
begin 
	insert into customers_archived values (old);
end $$
DELIMITER ;

-- AUDIT

-- create audit tables 

create table audit_hr ( id int auto_increment, action_type varchar(50), table varchar(50), action_date varchar(50) );
create table audit_store ( id int auto_increment, action_type varchar(50),  table_name varchar(50), action_date varchar(50) );
create table audit_invoicing ( id int auto_increment, action_type varchar(50),  table_name varchar(50), action_date varchar(50) );
create table audit_inventory ( id int auto_increment, action_type varchar(50),  table_name varchar(50), action_date varchar(50) );

-- create triggers

-- hr
use hr;
DELIMITER $$
create trigger employes_update
before delete on employes
for each row 
begin 
	insert into audit_hr (default, 'update' , 'employes', now() );
end $$
DELIMITER ;

use store;
show triggers;


