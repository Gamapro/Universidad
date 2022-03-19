use store;

select * from customers c
where c.id in(
	select id from order_items o where o.product_id=3	
);

select * from products
where unit_price > (select unit_price from products where id = 2);


use invoicing;

select * from clients c where c.id not in
( select distinct client_id from invoices);

select * from invoices;
