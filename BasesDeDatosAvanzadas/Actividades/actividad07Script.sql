use invoicing;

drop procedure if exists get_invoices_with_balance;
DELIMITER $$
create procedure get_invoices_with_balance()
begin
	select *, invoice_total - payment_total as balance from invoices;
end$$
DELIMITER ;
call get_invoices_with_balance();

drop procedure if exists get_payment_methods;
DELIMITER $$
create procedure get_payment_methods()
begin
	select * from payment_methods;
end$$
DELIMITER ;
call get_payment_methods();

drop procedure if exists get_payments;
DELIMITER $$
create procedure get_payments()
begin
	select * from payments;
end$$
DELIMITER ;
call get_payments();


use store;

drop procedure if exists get_products;
DELIMITER $$
create procedure get_products()
begin
	select * from products;
end$$
DELIMITER ;
call get_products();

drop procedure if exists get_order_items;
DELIMITER $$
create procedure get_order_items()
begin
	select * from order_items;
end$$
DELIMITER ;
call get_order_items();

drop procedure if exists get_order_statuses;
DELIMITER $$
create procedure get_order_statuses()
begin
	select * from order_statuses;
end$$
DELIMITER ;
call get_order_statuses();

drop procedure if exists get_orders;
DELIMITER $$
create procedure get_orders()
begin
	select * from orders;
end$$
DELIMITER ;
call get_orders();

drop procedure if exists get_store_products;
DELIMITER $$
create procedure get_store_products()
begin
	select * from products;
end$$
DELIMITER ;
call get_store_products();

drop procedure if exists get_shippers;
DELIMITER $$
create procedure get_shippers()
begin
	select * from shippers;
end$$
DELIMITER ;
call get_shippers();


use inventory;

drop procedure if exists get_inventory_products;
DELIMITER $$
create procedure get_inventory_products()
begin
	select * from products;
end$$
DELIMITER ;
call get_inventory_products();



use hr;

drop procedure if exists get_employees;
DELIMITER $$
create procedure get_employees()
begin
	select * from employees;
end$$
DELIMITER ;
call get_employees();

drop procedure if exists get_offices;
DELIMITER $$
create procedure get_offices()
begin
	select * from offices;
end$$
DELIMITER ;
call get_offices();

