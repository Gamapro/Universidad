
-- create database AgenciaEjercicio

use AgenciaEjercicio

/* create table Persona
(
	INE nvarchar(50) primary key,
	nombre nvarchar(100) not null,
	apellidos nvarchar(100) not null,
	direccion nvarchar(100) not null,
	telefono nvarchar(100) not null,
	poblacion nvarchar(100) not null
)

create table Accidente
(
	NumeroDeReferencia nvarchar(50) primary key,
	Fecha nvarchar(100) not null,
	Lugar nvarchar(100) not null,
	Hora nvarchar(100) not null,
	INE nvarchar(50) not null,
	foreign key (INE) references Persona(INE)
)*/

create table Vehiculo
(
	Matricula nvarchar(50) primary key,
	Marca nvarchar(100) not null,
	Modelo nvarchar(100) not null,
	NumeroDeReferencia nvarchar(50) not null,
	INE nvarchar(50) not null,
	foreign key (NumeroDeReferencia) references Accidente(NumeroDeReferencia),
	foreign key (INE) references Persona(INE)
)

create table Deducible
(
	NumeroDeReferencia nvarchar(50) primary key,
	Fecha nvarchar(100) not null,
	Lugar nvarchar(100) not null,
	Hora nvarchar(100) not null,
	Monto nvarchar(100) not null,
	Matricula nvarchar(50) not null,
	foreign key (NumeroDeReferencia) references Accidente(NumeroDeReferencia)
)