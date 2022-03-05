
use classicmodels;

-- 1. Calcular el límite de crédito máximo de los customers *

select * from customers
where creditLimit = (select max(creditLimit) from customers);

-- 2. Listar nombre y teléfono de los empleados que presentan error en su correo electrónico *

select firstName, lastName, email from employees
where email not like '%@classicmodelcars.com';

-- 3. Contar los customers sin línea de crédito *

select count(creditLimit) totalSinCredito from customers
where creditLimit = 0.0; 

-- 4. Listar los customers con país en el continente americano *

select * from customers
where country in ('USA','Canada','Mexico');

-- 5. Listar las ordenes enviadas detalladas con el nombre y apellido del usuario *

select c.contactFirstName, c.contactLastName, o.orderNumber, o.status, o.comments from orders o
join customers c on c.customerNumber = o.customerNumber
where o.status like 'Shipped';

-- 6. Listar los detalles de ordenes y en lugar del id del producto mostrar el nombre de *
-- este, además de mostrar la cantidad total según sea la cantidad ordenada y el
-- precio de la unidad

select od.orderNumber, p.productName ,od.quantityOrdered, od.priceEach
, od.quantityOrdered*od.priceEach total, od.orderLineNumber 
from orderdetails od
join products p on p.productCode = od.productCode;

-- 7. Calcular la suma de los límites de crédito de los customers por país *

select country, sum(creditLimit) suma from customers
group by country;

-- 8. Listar el número de customers por país *

select country, count(country) total from customers
group by country;

-- 9. Listar el nombre completo y nivel de los customers según su límite de crédito *
	-- 1. Bronce:0 a 50,000
	-- 2. Plata: 50,001 a 100,000
	-- 3. Oro: 100,001 a 150,000
	-- 4. Diamante: Mas de 150,000

select contactLastName, contactFirstName, 'Diamante' nivel from customers where creditLimit > 150000.0
union
select contactLastName, contactFirstName, 'Oro' nivel from customers where creditLimit between 100001.0 and 150000.0
union
select contactLastName, contactFirstName, 'Plata' nivel from customers where creditLimit between 50001.0 and 100000.0
union
select contactLastName, contactFirstName, 'Bronce' nivel from customers where creditLimit between 0.0 and 50000.0;

-- 10.Listar completamente todos los empleados desglosando el nombre completo de  *
-- su jefe inmediato y el teléfono junto dirección completa y estado de su oficina
	
select concat(emp.firstName,' ' ,emp.lastName) as employeeName, concat(boss.firstName,' ',boss.lastName) as bossName
, o.phone , emp.extension, o.state, o.addressLine1 address
from employees emp
join offices o on o.officeCode = emp.officeCode
join employees boss on emp.reportsTo = boss.employeeNumber;
