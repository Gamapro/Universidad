-- create database waifus

use waifus

drop table CharactersTags
drop table Characters
drop table Tags
drop table Creators
drop table Series

create table Creators(
	id int not null primary key,
	name varchar(100) default null
);

create table Series(
	id int not null primary key,
	name nvarchar(100) not null,
	description nvarchar(3000) default null,
);

create table Characters(
	id int not null primary key, 
	name nvarchar(100) not null,
	birthday_day int default null,
	birthday_month nvarchar(20) default null,
	birthday_year nvarchar(20) default null,
	age int default 0,
	height float default 0.0,
	weight float default 0.0,
	bust nvarchar(20) default null,
	waist nvarchar(20) default null,
	hip nvarchar(20) default null,
	description nvarchar(3000) default null,
	displayPicture nvarchar(100) default null,
	alternative_name nvarchar(100) default null,
	likes nvarchar(100) default null,
	creatorId int not null,
	seriesId int not null,
	foreign key (creatorId) references Creators(id),
	foreign key (seriesId) references Series(id)
);

create table Tags(
	id int not null primary key,
	name nvarchar(100) default null
);

create table CharactersTags(
	id int not null primary key,
	idCharacter int not null,
	idTag int not null
	foreign key (idCharacter) references Characters(id),
	foreign key (idTag) references Tags(id)
);