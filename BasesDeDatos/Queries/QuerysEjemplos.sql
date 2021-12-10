-- RESTORE DATABASE AdventureWorks2017
-- FROM DISK = 'C:\SQLServer\AdventureWorks2017.bak' 

-- use AdventureWorks2017

-- EJEMPLOS

-- Contar num empleados
-- select count(1) TotalEmpleados from HumanResources.Employee

-- Total hombres y mujeres
-- select Gender,count(1) Total from HumanResources.Employee group by Gender		
/* select case when Gender='M' then 'Male' when Gender='F' then 'Female'end Gender,count(1) Total 
from HumanResources.Employee 
group by Gender order by Total desc -- asc */ 

-- Total empleados casados o solteros
/*select case when MaritalStatus='S' then 'Soltero(a)' when MaritalStatus='M' then 'Casado(a)' end
MaritalStatus, count(1) Estado 
from HumanResources.Employee group by MaritalStatus*/

-- Total empleados grupo por genero y estado marital
/*select 
case when MaritalStatus='S' then 'Soltero(a)' when MaritalStatus='M' then 'Casado(a)' end 
MaritalStatus, 
case when Gender='M' then 'Hombre' when Gender='F' then 'Mujer'end
Gender,
count(1) Total from HumanResources.Employee group by Gender,MaritalStatus order by Gender, MaritalStatus
*/

-- Total de empleados por departamento
-- Join examples

select dep.Department, count(1) Total from HumanResources.Employee emp, HumanResources.vEmployeeDepartment dep 
where emp.BusinessEntityID=dep.BusinessEntityID
group by dep.Department
order by dep.Department

select dep.Department, count(1) Total from HumanResources.Employee emp
join HumanResources.vEmployeeDepartment dep on emp.BusinessEntityID=dep.BusinessEntityID
group by dep.Department
order by dep.Department


select ISNULL(p.Title,'')+' '+p.FirstName+' '+p.LastName Nombres from HumanResources.Employee emp
join Person.Person p on emp.BusinessEntityID=p.BusinessEntityID


select ISNULL(p.Title,'')+' '+p.FirstName+' '+p.LastName Nombres, dep.Department Departamento
from HumanResources.Employee emp
join Person.Person p on emp.BusinessEntityID=p.BusinessEntityID
join HumanResources.vEmployeeDepartment dep on emp.BusinessEntityID=dep.BusinessEntityID
where dep.Department not in ('Document Control') 
and p.FirstName like 'J%'
order by Departamento, Nombres


-- Sumas

select * from Sales.SalesPersonQuotaHistory

select sum(SalesQuota) from Sales.SalesPersonQuotaHistory

select year(QuotaDate) Fecha from Sales.SalesPersonQuotaHistory 
order by Fecha 

select year(QuotaDate) Fecha, sum(SalesQuota) Ventas from Sales.SalesPersonQuotaHistory 
group by year(QuotaDate)
order by Fecha desc, Ventas

