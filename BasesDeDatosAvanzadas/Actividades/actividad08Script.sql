use invoicing;

drop procedure if exists get_invoices_by_client;
DELIMITER $$
create procedure get_invoices_by_client(client_id int)
begin
	select * from clients c
    where c.id = client_id;
end$$
DELIMITER ;
call get_invoices_by_client(1);
call get_invoices_by_client(2);




use store;

create or replace view customers_points_category as
select id,first_name, last_name,birth_date,points, 
case
	when points > 1999 then 'oro'
    when points between 1000 and 1999 then 'plata'
    when points < 1000 then 'bronce' 
end as category from customers
order by id;

drop procedure if exists get_clients_by_category;
DELIMITER $$
create procedure get_clients_by_category(category varchar(15))
begin
	select id,first_name, last_name,birth_date,points, category as category
    from customers_points_category cpc
	where category = cpc.category;
end$$
DELIMITER ;
call get_clients_by_category('oro');
call get_clients_by_category('plata');
call get_clients_by_category('bronce');
