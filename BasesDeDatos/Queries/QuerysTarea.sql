-- RESTORE DATABASE AdventureWorks2017
-- FROM DISK = 'C:\SQLServer\AdventureWorks2017.bak' 

-- use AdventureWorks2017

-- Ejercicio 1

select year(DueDate) Fecha, sum(LineTotal) Total from Purchasing.PurchaseOrderDetail
group by year(DueDate)
order by Fecha desc

-- Ejercicio 2

select p.Name Nombre, sum(sale.ReceivedQty) Total from Production.Product pjoin Purchasing.PurchaseOrderDetail sale on sale.ProductID = p.ProductIDgroup by p.Nameorder by Total asc-- Ejercicio 3select Name Nombre, count(sale.ShipMethodID) Total from Sales.SalesOrderHeader salejoin Purchasing.ShipMethod p on p.ShipMethodID=sale.ShipMethodIDgroup by Name, sale.ShipMethodID-- Ejercicio 4select year(OrderDate) Fecha, sum(TaxAmt) Total_Impuestos from Sales.SalesOrderHeadergroup by year(OrderDate)order by Fecha asc-- Ejercicio 5select Name Region, year(OrderDate) Fecha, sum(TotalDue) Total from Sales.SalesOrderHeader salejoin Sales.SalesTerritory territory on territory.TerritoryID = sale.TerritoryIDgroup by Name, year(OrderDate)order by Region, Fecha desc