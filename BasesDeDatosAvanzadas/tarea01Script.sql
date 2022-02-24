use store;

-- Customers ordenados por id
select id, first_name nombre, last_name apellido, adress direccion from customers
order by id asc;

-- Customers ordenados por puntos
select points, first_name nombre, last_name apellido, adress direccion from customers
order by points asc;

-- Customers ordenados milenials o mas jovenes
select * from customers
where birth_date >= '1980-01-01';

-- Customers zona norte
select * from customers
where city in ('Baja California Sur', 'Baja California Nte', 'Chihuahua', 'Durango', 'Nuevo Leon'
	'Sonora', 'Sinaloa', 'Tamaulipas', 'Zacatecas'
);

-- Customers milenials con mas de 1000 puntos
select * from customers
where birth_date between '1980-01-01' and '1999-12-31'
and points > 1000;

-- Customers milenials o menores o con mas de 1000 puntos
select * from customers
where birth_date > '1980-01-01'
or points > 1000;

-- Customers milenials con mas de 1000 puntos en zona norte
select * from customers
where birth_date between '1980-01-01' and '1999-12-31'
and points > 1000 and city in ('Baja California Sur', 'Baja California Nte', 'Chihuahua', 'Durango', 'Nuevo Leon'
	'Sonora', 'Sinaloa', 'Tamaulipas', 'Zacatecas'
);

-- Customers NO milenials o menores con menos de 1000 puntos
select * from customers
where birth_date < '1980-01-01'
and points < 1000;

-- Customers NO zona norte
select * from customers
where city not in ('Baja California Sur', 'Baja California Nte', 'Chihuahua', 'Durango', 'Nuevo Leon'
	'Sonora', 'Sinaloa', 'Tamaulipas', 'Zacatecas'
);

-- ARTICULOS --

select *, quantity*unit_price Total from order_items;

-- id 6 ordenados
select *, quantity*unit_price Total from order_items
where id=6 and quantity*unit_price>3000
order by Total;