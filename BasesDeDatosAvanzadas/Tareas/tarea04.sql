use hr;

create or replace view employees_above_salary as
select * from employees
where salary > (select avg(salary) from employees);


use invoicing;

create or replace view clients_with_no_activity as
select * from clients c
where c.name not in
(
	select c.name from clients c
	join invoices i on c.id = i.client_id
	group by c.name
);


create or replace view payments_summary as
select pm.name, sum(amount) as total from payments p
join payment_methods pm on p.payment_method = pm.id
group by name;
