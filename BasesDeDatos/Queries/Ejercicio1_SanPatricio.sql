
-- create database SanParicio

-- use SanParicio

create table Medico
(
	Codigo nvarchar(50) primary key,
	Nombre nvarchar(100) not null,
	Apellidos nvarchar(100) not null,
	Especialidad nvarchar(100) not null,
	Telefono nvarchar(100) not null,
)

create table Paciente
(
	Codigo nvarchar(50) primary key,
	Nombre nvarchar(100) not null,
	Apellidos nvarchar(100) not null,
	Direccion nvarchar(100) not null,
	Telefono nvarchar(100) not null,
	Ciudad nvarchar(100) not null,
	Estado nvarchar(100) not null,
	CodigoPostal nvarchar(100) not null,
	FechaDeNacimiento nvarchar(100) not null
)

create table Ingreso
(
	Codigo nvarchar(50) primary key,
	FechaIngreso nvarchar(100) not null,
	FechaAlta nvarchar(100) not null,
	NumeroDeCama nvarchar(100) not null,
	NumeroDeHabitacion nvarchar(100) not null,
	CodigoPaciente nvarchar(50) not null,
	CodigoMedico nvarchar(50) not null,
	foreign key (CodigoPaciente) references Paciente(Codigo),
	foreign key (CodigoMedico) references Medico(Codigo)
)
