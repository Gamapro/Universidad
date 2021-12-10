
create database BaseCreditos
use BaseCreditos

-- Gestion y control para generacion de creditos 
-- Control sobre creditos, clientes y avales

--------------------------- CREACION DE TABLAS ---------------------------

/*
drop table Credito
drop table Cliente
drop table Aval 
*/

create table Cliente(
	CURP nvarchar(50) primary key,
	Nombres nvarchar(50) not null,
	Apellidos nvarchar(50) not null,
	Direccion nvarchar(100) not null,
	Telefono nvarchar(50) null,
	FechaDeNacimiento nvarchar(50) null,
	DireccionDeTrabajo nvarchar(100) null,
	TelefonoDeTrabajo nvarchar(50) null
)

create table Aval(
	ID int primary key,
	CURP nvarchar(50) not null,
	Nombres nvarchar(50) not null,
	Apellidos nvarchar(50) not null,
	Direccion nvarchar(100) not null,
	Telefono nvarchar(50) null,
	FechaDeNacimiento nvarchar(50) null,
	DireccionDeTrabajo nvarchar(100) null,
	TelefonoDeTrabajo nvarchar(50) null
)

create table Credito(
	Folio int primary key,
	Tipo nvarchar(50) not null,				-- linea blanca o prestamo en efectivo	 
	NumeroDeSemanas int not null,			-- 14, 28 o 36 
	Monto float not null,
	MontoDeAbono float not null,
	FechaDeEntrega nvarchar(50) null,
	Estatus	nvarchar(50) not null,			-- Activo, Cancelado, Finalizado
	ClienteID nvarchar(50) not null,
	Aval1 int null,
	Aval2 int null,
	foreign key (ClienteID) references Cliente(CURP),
	foreign key (Aval1) references Aval(ID),
	foreign key (Aval2) references Aval(ID) 
)

/*	Ligado a un cliente, un cliente puede tener varios creditos
-	Dependiendo del monto prestado el crédito puede o no solicitar avales, quedando de la siguiente manera:
o	Menos de 5,000 sin aval.
o	Más de 5,000 y menos de 10,000 un aval.	
o	Más de 10,000 dos avales
-	Al igual que un cliente un aval puede pertenecer a uno o más créditos.*/











--------------------------- INSERCIONES ---------------------------

-- Insertar a Jose Velarde

insert into Cliente
(CURP, Nombres, Apellidos, Direccion, Telefono, FechaDeNacimiento, DireccionDeTrabajo, TelefonoDeTrabajo)
values 
('AOBG10101029', 'Jose', 'Velarde', 'Rio Grande', 4499191199,
'23-03-1989', 'Jose Maria', 2534523454
)

-- Aval Sergio Velarde

insert into Aval
(ID, CURP, Nombres, Apellidos, Direccion, Telefono, FechaDeNacimiento, DireccionDeTrabajo, TelefonoDeTrabajo)
values 
(
	(select count(ID) + 1 from Aval),
	'AOBG40123029', 'Sergio', 'Velarde', 'Rio Chico', 4499164192,
	'12-01-1989', 'Piedra Grande', null
)

-- Aval Maribel Velarde

insert into Aval
(ID, CURP, Nombres, Apellidos, Direccion, Telefono, FechaDeNacimiento, DireccionDeTrabajo, TelefonoDeTrabajo)
values 
(
	(select count(ID) + 1 from Aval),
	'AOBG4554BN029', 'Maribel', 'Velarde', 'Rio Mediano', 4399145196,
	'12-12-1994', 'Salita', 5773723
)

-- Crédito Personal 14 semanas 5000 A nombre de José Velarde (Abono 357.14).

insert into Credito
( Folio, Tipo, NumeroDeSemanas, Monto, MontoDeAbono, FechaDeEntrega, Estatus, ClienteID, Aval1, Aval2)
values
(	(select count(Folio) + 1 from Credito),
	'Personal', 14, 5000.0, 357.14, '29-02-2012', 'Activo', 
	(select CURP from Cliente where (Nombres='Jose' and Apellidos='Velarde') ),
	null, null
)

-- Crédito Personal 28 semanas 10,000 A nombre de José Velarde, aval Sergio Velarde (Abono 357.14).

insert into Credito
( Folio, Tipo, NumeroDeSemanas, Monto, MontoDeAbono, FechaDeEntrega, Estatus, ClienteID, Aval1, Aval2)
values
(	(select count(Folio) + 1 from Credito),
	'Personal', 28, 10000.0, 357.14, '12-12-2019', 'Activo', 
	(select CURP from Cliente where (Nombres='Jose' and Apellidos='Velarde') ),
	(select ID from Aval where (Nombres='Sergio' and Apellidos='Velarde') ),
	null
)

-- Crédito Personal 36 semanas 15,000 A nombre de José Velarde, aval Sergio Velarde, Maribel Velarde (Abono 416.66).

insert into Credito
( Folio, Tipo, NumeroDeSemanas, Monto, MontoDeAbono, FechaDeEntrega, Estatus, ClienteID, Aval1, Aval2)
values
(	(select count(Folio) + 1 from Credito),
	'Personal', 36, 15000.0, 416.66, '25-12-2019', 'Activo', 
	(select CURP from Cliente where (Nombres='Jose' and Apellidos='Velarde') ),
	(select ID from Aval where (Nombres='Sergio' and Apellidos='Velarde') ),
	(select ID from Aval where (Nombres='Maribel' and Apellidos='Velarde') )
)

-- Cambiar el estatus a cancelado del crédito personal de 14 semanas del cliente José Velarde.

update Credito set Estatus='Cancelado' 
where Tipo='Personal' and NumeroDeSemanas=14 and 
exists(select CURP from Cliente where (Nombres='Jose' and Apellidos='Velarde'))


-- Insertar 3 Créditos Personales a 14 semanas por 5000 a nombre de nuevos clientes (Abono 357.14).

insert into Cliente
(CURP, Nombres, Apellidos, Direccion, Telefono, FechaDeNacimiento, DireccionDeTrabajo, TelefonoDeTrabajo)
values 
('MANUBGAFADF29', 'Manuel', 'Hinojosa', 'Cono', 4499134199, '23-03-1999', 'Jose Morelos', 2534233454
)
insert into Cliente
(CURP, Nombres, Apellidos, Direccion, Telefono, FechaDeNacimiento, DireccionDeTrabajo, TelefonoDeTrabajo)
values 
('GENUNINUNID', 'Genaro', 'Barrabas', 'Alla', 4344345199, '23-03-2009', 'Jose', 2534524454
)
insert into Cliente
(CURP, Nombres, Apellidos, Direccion, Telefono, FechaDeNacimiento, DireccionDeTrabajo, TelefonoDeTrabajo)
values 
('1231NATA', 'Natalia', 'Esparza', 'Vallesito', 44856244199, '31-01-2013', 'Morelos', 2534524554
)


insert into Credito
( Folio, Tipo, NumeroDeSemanas, Monto, MontoDeAbono, FechaDeEntrega, Estatus, ClienteID, Aval1, Aval2)
values
(	(select count(Folio) + 1 from Credito), 'Personal', 14, 5000.0, 357.14, '29-02-2012', 'Activo', 
	(select CURP from Cliente where (Nombres='Genaro' and Apellidos='Barrabas') ),
	null, null
)

insert into Credito
( Folio, Tipo, NumeroDeSemanas, Monto, MontoDeAbono, FechaDeEntrega, Estatus, ClienteID, Aval1, Aval2)
values
(	(select count(Folio) + 1 from Credito), 'Personal', 14, 5000.0, 357.14, '29-02-2012', 'Activo', 
	(select CURP from Cliente where (Nombres='Natalia' and Apellidos='Esparza') ),
	null, null
)

insert into Credito
( Folio, Tipo, NumeroDeSemanas, Monto, MontoDeAbono, FechaDeEntrega, Estatus, ClienteID, Aval1, Aval2)
values
(	(select count(Folio) + 1 from Credito), 'Personal', 14, 5000.0, 357.14, '29-02-2012', 'Activo', 
	(select CURP from Cliente where (Nombres='Manuel' and Apellidos='Hinojosa') ),
	null, null
)


-- Insertar 2 Créditos Personales por 10000 a 28 semanas a nombre de nuevos clientes y nuevos avales (Abono 357.14).
insert into Cliente
(CURP, Nombres, Apellidos, Direccion, Telefono, FechaDeNacimiento, DireccionDeTrabajo, TelefonoDeTrabajo)
values 
('DAVIDGGG123', 'David', 'Arcos', 'Aquii', 4499991194, '31-12-2001', '1 Hacker Way', 4499991194
)
insert into Aval
(ID, CURP, Nombres, Apellidos, Direccion, Telefono, FechaDeNacimiento, DireccionDeTrabajo, TelefonoDeTrabajo)
values(
	(select count(ID) + 1 from Aval),
	'1231NATA', 'Natalia', 'Esparza', 'Vallesito', 44856244199, '31-01-2013', 'Morelos', 2534524554
)
insert into Aval
(ID, CURP, Nombres, Apellidos, Direccion, Telefono, FechaDeNacimiento, DireccionDeTrabajo, TelefonoDeTrabajo)
values(
	(select count(ID) + 1 from Aval),
	'1231JESUUUUS', 'Jesus', 'Espinoza', 'Vallesito', 44834344199, '02-03-2011', 'Morelos', 255363474
)

insert into Credito
( Folio, Tipo, NumeroDeSemanas, Monto, MontoDeAbono, FechaDeEntrega, Estatus, ClienteID, Aval1, Aval2)
values
(	(select count(Folio) + 1 from Credito),
	'Personal', 28, 10000.0, 357.14, '31-12-2021', 'Activo', 
	(select CURP from Cliente where (Nombres='David' and Apellidos='Arcos') ),
	(select ID from Aval where (Nombres='Natalia' and Apellidos='Esparza') ),
	null
)
insert into Credito
( Folio, Tipo, NumeroDeSemanas, Monto, MontoDeAbono, FechaDeEntrega, Estatus, ClienteID, Aval1, Aval2)
values
(	(select count(Folio) + 1 from Credito),
	'Personal', 28, 10000.0, 357.14, '31-12-2021', 'Activo', 
	(select CURP from Cliente where (Nombres='David' and Apellidos='Arcos') ),
	(select ID from Aval where (Nombres='Jesus' and Apellidos='Espinoza') ),
	null
)


-- Insertar 3 Créditos de Línea Blanca a 14 semanas por 5000 a nombre de nuevos clientes (Abono 357.14).

insert into Cliente
(CURP, Nombres, Apellidos, Direccion, Telefono, FechaDeNacimiento, DireccionDeTrabajo, TelefonoDeTrabajo)
values 
('FERZNANS', 'Fernanda', 'Ruvalcaba', 'Sonora', 441242342, '31-12-2002', 'Sonora', 441242342
)
insert into Cliente
(CURP, Nombres, Apellidos, Direccion, Telefono, FechaDeNacimiento, DireccionDeTrabajo, TelefonoDeTrabajo)
values 
('MELANIEEE12', 'Melanie', 'Lechuga', 'Sonora', 549034141, '31-12-2004', 'Sonora', 549034141
)
insert into Cliente
(CURP, Nombres, Apellidos, Direccion, Telefono, FechaDeNacimiento, DireccionDeTrabajo, TelefonoDeTrabajo)
values 
('SAULITO', 'Saul', 'Fenix', 'Culiacan', 245738473, '24-02-2004', 'Fresas', 245738473
)

insert into Credito
( Folio, Tipo, NumeroDeSemanas, Monto, MontoDeAbono, FechaDeEntrega, Estatus, ClienteID, Aval1, Aval2)
values
(	(select count(Folio) + 1 from Credito),
	'Linea Blanca', 14, 10000.0, 357.14, '23-02-2020', 'Activo', 
	(select CURP from Cliente where (Nombres='Fernanda' and Apellidos='Ruvalcaba') ),
	null, null
)
insert into Credito
( Folio, Tipo, NumeroDeSemanas, Monto, MontoDeAbono, FechaDeEntrega, Estatus, ClienteID, Aval1, Aval2)
values
(	(select count(Folio) + 1 from Credito),
	'Linea Blanca', 14, 10000.0, 357.14, '23-02-2020', 'Activo', 
	(select CURP from Cliente where (Nombres='Melanie' and Apellidos='Lechuga') ),
	null, null
)
insert into Credito
( Folio, Tipo, NumeroDeSemanas, Monto, MontoDeAbono, FechaDeEntrega, Estatus, ClienteID, Aval1, Aval2)
values
(	(select count(Folio) + 1 from Credito),
	'Linea Blanca', 14, 10000.0, 357.14, '23-02-2020', 'Activo', 
	(select CURP from Cliente where (Nombres='Saul' and Apellidos='Fenix') ),
	null, null
)

-- Insertar 2 Créditos Línea Blanca por 30000 a 14 semanas a nombre de nuevos clientes y nuevos avales (cabe mencionar que se requieren 2 avales en estos préstamos) (Abono 2142.85).

insert into Aval
(ID, CURP, Nombres, Apellidos, Direccion, Telefono, FechaDeNacimiento, DireccionDeTrabajo, TelefonoDeTrabajo)
values(
	(select count(ID) + 1 from Aval),
	'MELANIEEE12', 'Melanie', 'Lechuga', 'Sonora', 549034141, '31-12-2004', 'Sonora', 549034141
)
insert into Aval
(ID, CURP, Nombres, Apellidos, Direccion, Telefono, FechaDeNacimiento, DireccionDeTrabajo, TelefonoDeTrabajo)
values(
	(select count(ID) + 1 from Aval),
	'FERNANDOOO213', 'Fernando', 'Piolin', 'Calle sin nombre', 44999123124, '23-07-2011', 'Sabi', 44999123124
)
insert into Aval
(ID, CURP, Nombres, Apellidos, Direccion, Telefono, FechaDeNacimiento, DireccionDeTrabajo, TelefonoDeTrabajo)
values(
	(select count(ID) + 1 from Aval),
	'HAAANA', 'Kana', 'Hanazawa', 'Tokyo', 524515461, '24-06-2002', 'Kyoto', 524515461
)
insert into Aval
(ID, CURP, Nombres, Apellidos, Direccion, Telefono, FechaDeNacimiento, DireccionDeTrabajo, TelefonoDeTrabajo)
values(
	(select count(ID) + 1 from Aval),
	'SAAAA', 'Ayane', 'Sakura', 'Shibuya', 24144535, '23-07-2000', 'Chiba', 24144535
)

insert into Credito
( Folio, Tipo, NumeroDeSemanas, Monto, MontoDeAbono, FechaDeEntrega, Estatus, ClienteID, Aval1, Aval2)
values
(	(select count(Folio) + 1 from Credito),
	'Linea Blanca', 14, 30000.0, 2142.85, '31-12-2021', 'Activo', 
	(select CURP from Cliente where (Nombres='David' and Apellidos='Arcos') ),
	(select ID from Aval where (Nombres='Ayane' and Apellidos='Sakura') ),
	(select ID from Aval where (Nombres='Kana' and Apellidos='Hanazawa') )
)
insert into Credito
( Folio, Tipo, NumeroDeSemanas, Monto, MontoDeAbono, FechaDeEntrega, Estatus, ClienteID, Aval1, Aval2)
values
(	(select count(Folio) + 1 from Credito),
	'Linea Blanca', 14, 30000.0, 2142.85, '31-12-2021', 'Activo', 
	(select CURP from Cliente where (Nombres='Saul' and Apellidos='Fenix') ),
	(select ID from Aval where (Nombres='Melanie' and Apellidos='Lechuga') ),
	(select ID from Aval where (Nombres='Fernando' and Apellidos='Piolin') )
)








--------------------------- LISTADOS ---------------------------



-- Generar un listado que incluya el folio del crédito, monto del crédito, 
-- nombre completo del cliente y nombre completo del aval de los créditos activos.


select Folio, Monto, 
cl.Nombres+' '+cl.Apellidos NombreCliente,
av1.Nombres+' '+av1.Apellidos NombreAval1,
av2.Nombres+' '+av2.Apellidos NombreAval2 
from Credito cr
join Cliente cl on cr.ClienteID=cl.CURP
left join Aval av1 on cr.Aval1=av1.ID
left join Aval av2 on cr.Aval2=av2.ID
order by Folio

-- Generar un listado que incluya el id del cliente, 
-- el nombre del cliente y total de créditos que ha tenido dentro de la empresa.


select CURP ID, cl.Nombres+' '+cl.Apellidos Nombre, count( cl.CURP ) TotalCreditos
from Cliente cl
join Credito cr on cr.ClienteID=cl.CURP
group by CURP, cl.Nombres+' '+cl.Apellidos
order by CURP


-- Generar un listado que contenga los avales y el total de créditos avalados, el reporte mostrara el id del aval, 
-- el nombre del aval y total de créditos avalados.


select ID, av.Nombres+' '+av.Apellidos Nombre, count( av.ID ) TotalAvalados from Aval av
join Credito cr on cr.Aval1=av.ID or cr.Aval2=av.ID
group by ID, av.Nombres+' '+av.Apellidos
order by ID


-- Generar el total prestado para los créditos de tipo línea blanca y créditos personales, 
-- agrupados por tipo de crédito y numero de semanas y que actualmente se encuentran activos.


select Tipo, NumeroDeSemanas, count(Folio) NumeroDePrestamos, sum(Monto) TotalPrestado from Credito cr 
where Estatus='Activo'
group by Tipo, NumeroDeSemanas
