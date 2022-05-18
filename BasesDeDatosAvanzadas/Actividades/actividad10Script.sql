
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

drop table if exists audit_hr;

create table if not exists audit_hr ( id int , action_type varchar(50), table_name varchar(50), action_date varchar(50) );
create table if not exists audit_store ( id int , action_type varchar(50),  table_name varchar(50), action_date varchar(50) );
create table if not exists audit_invoicing ( id int , action_type varchar(50),  table_name varchar(50), action_date varchar(50) );
create table if not exists audit_inventory ( id int , action_type varchar(50),  table_name varchar(50), action_date varchar(50) );

-- create triggers

-- hr
use hr;
DELIMITER $$
create trigger employes_update
before delete osn employees
for each row 
begin 
	insert into audit_hrs (select(count(1), 'update', 'employees', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger employes_insert
before insert on employees
for each row 
begin 
	insert into audit_hrs (select(count(1), 'insert', 'employees', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger employes_delete
before update on employees
for each row 
begin 
	insert into audit_hrs (select(count(1), 'delete', 'employees', now()));
end $$
DELIMITER ;

DELIMITER $$
create trigger ofices_update
before delete on offices
for each row 
begin 
	insert into audit_hrs (select(count(1), 'update', 'offices', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger ofices_insert
before insert on offices
for each row 
begin 
	insert into audit_hrs (select(count(1), 'insert', 'offices', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger offices_delete
before update on offices
for each row 
begin 
	insert into audit_hrs (select(count(1), 'delete', 'offices', now()));
end $$
DELIMITER ;

use inventory;
DELIMITER $$
create trigger products_update
before delete on products
for each row 
begin 
	insert into audit_inventory (select(count(1), 'update', 'products', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger products_insert
before insert on products
for each row 
begin 
	insert into audit_inventory (select(count(1), 'insert', 'products', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger products_delete
before update on offices
for each row 
begin 
	insert into audit_inventory (select(count(1), 'delete', 'products', now()));
end $$
DELIMITER ;

use store;
DELIMITER $$
create trigger products_update
before delete on products
for each row 
begin 
	insert into audit_store (select(count(1), 'update', 'products', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger products_insert
before insert on products
for each row 
begin 
	insert into audit_store (select(count(1), 'insert', 'products', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger products_delete
before update on offices
for each row 
begin 
	insert into audit_store (select(count(1), 'delete', 'products', now()));
end $$
DELIMITER ;

use store;
DELIMITER $$
create trigger orders_update
before delete on orders
for each row 
begin 
	insert into audit_store (select(count(1), 'update', 'orders', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger orders_insert
before insert on orders
for each row 
begin 
	insert into audit_store (select(count(1), 'insert', 'orders', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger orders_delete
before update on orders
for each row 
begin 
	insert into audit_store (select(count(1), 'delete', 'orders', now()));
end $$
DELIMITER ;

DELIMITER $$
create trigger orders_archiveds_update
before delete on orders_archived
for each row 
begin 
	insert into audit_store (select(count(1), 'update', 'orders_archived', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger orders_archived_insert
before insert on orders_archived
for each row 
begin 
	insert into audit_store (select(count(1), 'insert', 'orders_archived', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger orders_archived_delete
before update on orders_archived
for each row 
begin 
	insert into audit_store (select(count(1), 'delete', 'orders_archived', now()));
end $$
DELIMITER ;

DELIMITER $$
create trigger orders_statuses_update
before delete on order_statuses
for each row 
begin 
	insert into audit_store (select(count(1), 'update', 'orders_statuses', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger orders_statuses_insert
before insert on order_statuses
for each row 
begin 
	insert into audit_store (select(count(1), 'insert', 'orders_statuses', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger orders_statuses_delete
before update on order_statuses
for each row 
begin 
	insert into audit_store (select(count(1), 'delete', 'orders_statuses', now()));
end $$
DELIMITER ;

DELIMITER $$
create trigger shippers_update
before delete on shippers
for each row 
begin 
	insert into audit_store (select(count(1), 'update', 'shippers', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger shippers_insert
before insert on shippers
for each row 
begin 
	insert into audit_store (select(count(1), 'insert', 'shippers', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger shippers_delete
before update on shippers
for each row 
begin 
	insert into audit_store (select(count(1), 'delete', 'shippers', now()));
end $$
DELIMITER ;

DELIMITER $$
create trigger order_items_update
before delete on order_items
for each row 
begin 
	insert into audit_store (select(count(1), 'update', 'order_items', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger order_items_insert
before insert on order_items
for each row 
begin 
	insert into audit_store (select(count(1), 'insert', 'order_items', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger order_items_delete
before update on order_items
for each row 
begin 
	insert into audit_store (select(count(1), 'delete', 'order_items', now()));
end $$
DELIMITER ;

DELIMITER $$
create trigger oorder_items_archived_update
before delete on order_items_archived
for each row 
begin 
	insert into audit_store (select(count(1), 'update', 'order_items_archived', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger oorder_items_archivedinsert
before insert on order_items_archived
for each row 
begin 
	insert into audit_store (select(count(1), 'insert', 'order_items_archived', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger order_items_archived_delete
before update on order_items_archived
for each row 
begin 
	insert into audit_store (select(count(1), 'delete', 'order_items_archived', now()));
end $$
DELIMITER ;

DELIMITER $$
create trigger order_items_notes_update
before delete on order_item_notes
for each row 
begin 
	insert into audit_store (select(count(1), 'update', 'order_items_notes', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger order_items_notes_insert
before insert on order_item_notes
for each row 
begin 
	insert into audit_store (select(count(1), 'insert', 'order_items_notes', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger order_items_notes_delete
before update on order_item_notes
for each row 
begin 
	insert into audit_store (select(count(1), 'delete', 'order_items_notes', now()));
end $$
DELIMITER ;

DELIMITER $$
create trigger customers_archived_update
before delete on customers_archived
for each row 
begin 
	insert into audit_store (select(count(1), 'update', 'customers_archived', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger customers_archived_insert
before insert on customers_archived
for each row 
begin 
	insert into audit_store (select(count(1), 'insert', 'customers_archived', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger customers_archived_delete
before update on customers_archived
for each row 
begin 
	insert into audit_store (select(count(1), 'delete', 'customers_archived', now()));
end $$
DELIMITER ;

DELIMITER $$
create trigger ccustomersd_update
before delete on customers
for each row 
begin 
	insert into audit_store (select(count(1), 'update', 'customers', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger customers_insert
before insert on customers
for each row 
begin 
	insert into audit_store (select(count(1), 'insert', 'customers', now()));
end $$
DELIMITER ;
DELIMITER $$
create trigger customers_delete
before update on customers
for each row 
begin 
	insert into audit_store (select(count(1), 'delete', 'customers', now()));
end $$
DELIMITER ;



use store;
show triggers;


