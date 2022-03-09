-- RESTORE DATABASE AdventureWorks2017
-- FROM DISK = 'C:\SQLServer\AdventureWorks2017.bak' 

-- use AdventureWorks2017

-- Ejercicio 1

select year(DueDate) Fecha, sum(LineTotal) Total from Purchasing.PurchaseOrderDetail
group by year(DueDate)
order by Fecha desc

-- Ejercicio 2

select p.Name Nombre, sum(sale.ReceivedQty) Total from Production.Product p