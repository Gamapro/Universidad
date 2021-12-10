
-- create database EmpresaEjercicio

-- use EmpresaEjercicio

create table Colaborador
(
	INE nvarchar(50) primary key,
	Nombre nvarchar(100) not null,
	Domicilio nvarchar(100) not null,
	Banco nvarchar(100) not null,
	NumeroDeCuenta nvarchar(100) not null
)

create table Cliente
(
	Codigo nvarchar(50) primary key,
	Telefono nvarchar(100) not null,
	Domicilio nvarchar(100) not null,
	RFC nvarchar(100) not null
)

create table Proyecto
(
	Codigo nvarchar(50) primary key,
	Inicio nvarchar(100) not null,
	Fin nvarchar(100) not null,
	Descripcion nvarchar(100) not null,
	Costo nvarchar(100) not null,
	INE nvarchar(50) not null,
	foreign key (INE) references Colaborador(INE),
	CodigoCliente nvarchar(50) not null,
	foreign key (CodigoCliente) references Cliente(Codigo)
)

create table Vehiculo
(
	NumeroDePago nvarchar(50) primary key,
	Concepto nvarchar(100) not null,
	Cantidad nvarchar(100) not null,
	FechaDePago nvarchar(50) not null,
	TipoDePago nvarchar(50) not null,
	Descripcion nvarchar(50) not null,
	INE nvarchar(50) not null,
	foreign key (INE) references Colaborador(INE)
)

