
use store;

select * from order_items o
join products p on o.id = p.id;

select oi.product_id, p.name, count(1) orders, 
IF(count(1) > 1, "Multiple", "Individual") as frecuencia
from order_items oi
join products p on oi.id = p.id
group by oi.product_id
order by oi.product_id;


use store;

select id,first_name, last_name,birth_date,points,
case 
	when birth_date between '1980-01-01' and '1999-12-31' then 'Milenial'
    when birth_date between '1965-01-01' and '1979-12-31' then 'GenX'
    when birth_date between '1946-01-01' and '1964-12-31' then 'Baby Boomer'
end as generation from customers
order by id;

select id,first_name, last_name,birth_date,points, 
case
	when points > 1999 then 'oro'
    when points between 1000 and 1999 then 'plata'
    when points < 1000 then 'bronce' 
end as category from customers
order by id;


