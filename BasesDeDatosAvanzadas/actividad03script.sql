use store;

select * from customers;


select id,first_name, last_name,birth_date,points, 'Milenial' as generation from customers
where birth_date between '1980-01-01' and '1999-12-31'
union
select id,first_name, last_name,birth_date,points, 'GenY' as generation from customers
where birth_date between '1965-01-01' and '1979-12-31'
order by id;

select id,first_name, last_name,birth_date,points, 'oro' as category from customers
where points > 1999
union
select id,first_name, last_name,birth_date,points, 'plata' as category from customers
where points between 1000 and 1999
union
select id,first_name, last_name,birth_date,points, 'bronce' as category from customers
where points < 1000
order by id;


