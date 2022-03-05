
use store;

select * from orders
join store.customers c on c.id = orders.id;

select * from orders od
join store.customers c on c.id = od.customer_id
join order_statuses os on os.id = od.statuses
order by od.id;

select * from orders
join shippers s on s.id = orders.shipper_id;

select * from order_items
join products p on order_items.product_id = p.id;

select * from orders
left join store.customers c on c.id = orders.customer_id
left join shippers s on s.id = orders.shipper_id
left join order_statuses os on orders.statuses = os.id;


use hr;

select *, o.first_name boos_name, o.last_name boss_last_name from employees o
join employees on o.id = employees.reports_to;

