use invoicing;

drop procedure if exists get_invoices_with_balance_id;
DELIMITER $$
create procedure get_invoices_with_balance_id(id int)
begin
	select *, invoice_total - payment_total as balance from invoices inv
    where inv.id = id;
end$$
DELIMITER ;
call get_invoices_with_balance_id(4);

drop procedure if exists get_payment_methods_id;
DELIMITER $$
create procedure get_payment_methods_id(id int)
begin
	select * from payment_methods pm
    where pm.id = id;
end$$
DELIMITER ;
call get_payment_methods_id(2);

drop procedure if exists get_payments_id;
DELIMITER $$
create procedure get_payments_id(id int)
begin
	select * from payments p where p.id = id;
end$$
DELIMITER ;
call get_payments_id(3);


use store;

drop procedure if exists get_products_id;
DELIMITER $$
create procedure get_products_id(id int)
begin
	select * from products p where id = p.id;
end$$
DELIMITER ;
call get_products_id(3);

drop procedure if exists get_order_items_id;
DELIMITER $$
create procedure get_order_items_id(id int)
begin
	select * from order_items oi where id = oi.id;
end$$
DELIMITER ;
call get_order_items_id(3);

drop procedure if exists get_order_statuses_id;
DELIMITER $$
create procedure get_order_statuses_id(id int)
begin
	select * from order_statuses os where os.id = id;
end$$
DELIMITER ;
call get_order_statuses_id(1);

drop procedure if exists get_orders_id;
DELIMITER $$
create procedure get_orders_id(id int)
begin
	select * from orders o where o.id = id;
end$$
DELIMITER ;
call get_orders_id(1);

drop procedure if exists get_store_products_id;
DELIMITER $$
create procedure get_store_products_id(id int)
begin
	select * from products p where id = p.id;
end$$
DELIMITER ;
call get_store_products_id(3);

drop procedure if exists get_shippers_id;
DELIMITER $$
create procedure get_shippers_id(id int)
begin
	select * from shippers s where id = s.id;
end$$
DELIMITER ;
call get_shippers_id(3);


use inventory;

drop procedure if exists get_inventory_products_id;
DELIMITER $$
create procedure get_inventory_products_id(id int)
begin
	select * from products p where id = p.id;
end$$
DELIMITER ;
call get_inventory_products_id(0);



use hr;

drop procedure if exists get_employees_id;
DELIMITER $$
create procedure get_employees_id(id int)
begin
	select * from employees em where id = em.id;
end$$
DELIMITER ;
call get_employees_id(37270);

drop procedure if exists get_offices_id;
DELIMITER $$
create procedure get_offices_id(id int)
begin
	select * from offices o where o.id = id;
end$$
DELIMITER ;
call get_offices_id(2);

