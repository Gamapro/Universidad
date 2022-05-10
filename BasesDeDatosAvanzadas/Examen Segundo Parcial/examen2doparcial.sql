
use pokemon;

-- tipo = 3 ='flying'
-- habitat = 3 = 'grassland'

-- 1. CREAR UNA VISTA [MMDISIMO_POKEMON]
-- • Vista de los Pokémon con ataque, defensa y HP superiores a 100

create or replace view MMDISIMO_POKEMON as
select p.pok_name as name, p.pok_id, p.pok_alt, p.pok_peso, p.pok_base_exp, b_hp, b_def, b_atk from pokemon p 
join estadisticas_base e on p.pok_id = e.pok_id
where b_hp > 100 and b_def > 100 and b_atk > 100;

-- 2. CREAR UNA VISTA [<HABITAT>_POKEMON] = 
-- • Vista de los Pokémon y su hábitat

create or replace view GRASSLAND_POKEMON as
select p.pok_name as name, p.pok_id, p.pok_alt, p.pok_peso, p.pok_base_exp, hab_name, hab_descript from pokemon p
join pokemon_evolucion_relacion pr on pr.pok_id = p.pok_id
join pokemon_habitats ph on pr.hab_id = ph.hab_id
where ph.hab_name = 'grassland';

-- 3. CREAR UNA VISTA [HABILIDADES_POKEMON]
-- • Vista de los Pokémon y todas sus habilidades.

create or replace view HABILIDADES_POKEMON as
select p.pok_name as name, p.pok_id, p.pok_alt, p.pok_peso, p.pok_base_exp, h.habil_name, h.habil_id from pokemon_habilidades ph
join habilidades h on h.habil_id = ph.habil_id
join pokemon p on p.pok_id = ph.pok_id;

-- 4. CREAR UNA VISTA [PUNTAJE_POKEMON]
-- • Vista de la suma de todas las estadísticas básicas de los Pokémon y los muestra
-- como un puntaje total.

create or replace view PUNTAJE_POKEMON as 
select p.pok_name as name, t.type_name, p.pok_id, p.pok_alt, p.pok_peso, p.pok_base_exp, (
    sum(`eb`.`b_hp`)+
    sum(`eb`.`b_atk`)+
    sum(`eb`.`b_def`)+
    sum(`eb`.`b_sp_atk`)+
    sum(`eb`.`b_sp_def`)+
	sum(`eb`.`b_speed`)) as puntaje_total from estadisticas_base eb
join pokemon p on p.pok_id = eb.pok_id
join pokemon_tipos pt on pt.pok_id = p.pok_id
join tipos t on t.tipo_id = pt.tipo_id
group by p.pok_id;

-- 5. CREAR UNA VISTA [TOP<TIPO>_POKEMON]
-- • Vista de las 10 mejores estadísticas base de los Pokémon según su tipo.

create or replace view TOP_FLYING_POKEMON as
select * from PUNTAJE_POKEMON 
where type_name='flying'
order by puntaje_total desc limit 10;

-- 6. CREAR UN STORE PROCEDURE [POKEVOLUCION_POKEMON(poke_id)]
-- • Introduce el id de un Pokémon y devuelve su nombre y evolución.

drop procedure if exists POKEVOLUCION_POKEMON;
DELIMITER $$
create procedure POKEVOLUCION_POKEMON(id int)
begin
	select pev.pok_name as nombre, p.pok_name  as evolucion from pokemon p
	join pokemon_evolucion_relacion per on per.pok_id=p.pok_id
	join pokemon pev on pev.pok_id = per.evolves_from_species_id
	where pev.pok_id = id;    
end$$
DELIMITER ;
call POKEVOLUCION_POKEMON(1);
call POKEVOLUCION_POKEMON(2);
call POKEVOLUCION_POKEMON(3);

-- 7. CREAR UN STORE PROCEDURE [RESITE_ATAQUE(poke_name, atack_name]
-- • Introduce un movimiento y el nombre del Pokémon. hay retorno si el Pokémon
-- se ha desmayado. Si no hay respuesta, el Pokémon no se ha desmayado..

drop procedure if exists RESISTE_ATAQUE;
DELIMITER $$
create procedure RESISTE_ATAQUE(poke_name varchar(80), atack_name varchar(80))
begin
    select p.pok_name, eb.b_hp, atack_name as ataque,
    (select movi_power from movimientos where movi_name=atack_name) as ataque_poder
    , if(b_hp - (select movi_power from movimientos where movi_name=atack_name) > 0,
    b_hp - (select movi_power from movimientos where movi_name=atack_name),
	'Desmayado') as	vida_restante
    from pokemon p
    join estadisticas_base eb on p.pok_id = eb.pok_id
    where poke_name = p.pok_name;
end$$
DELIMITER ;
call RESISTE_ATAQUE('bulbasaur','cut');
call RESISTE_ATAQUE('bulbasaur','wrap');
call RESISTE_ATAQUE('charizard','cut');
call RESISTE_ATAQUE('charizard','wrap');
call RESISTE_ATAQUE('venusaur','cut');
call RESISTE_ATAQUE('venusaur','wrap');

-- 8. CREAR UN STORE PROCEDURE [TIPO DE MOVIMIENTO(mov_name)]
-- • Introduce el movimiento de un Pokémon y devuelve el tipo de movimiento.

drop procedure if exists TIPO_DE_MOVIMIENTO;
DELIMITER $$
create procedure TIPO_DE_MOVIMIENTO(mov_name varchar(80) )
begin
	select movi_name, type_name from movimientos m
	join tipos t on t.tipo_id = m.tipo_id
    where movi_name = mov_name;
end$$
call TIPO_DE_MOVIMIENTO('double-slap');
call TIPO_DE_MOVIMIENTO('cut');
call TIPO_DE_MOVIMIENTO('wrap');

-- 9. CREAR UN STORE PROCEDURE [TIPO_POKEMON(poke_name)]
-- • Introduce el nombre de un Pokémon y devuelve su tipo.

drop procedure if exists TIPO_POKEMON;
DELIMITER $$
create procedure TIPO_POKEMON(name_pok varchar(80))
begin
    select p.pok_name as name, t.type_name, p.pok_id, p.pok_alt, p.pok_peso, p.pok_base_exp from pokemon p
    join pokemon_tipos pt on pt.pok_id = p.pok_id
	join tipos t on t.tipo_id = pt.tipo_id
    where name_pok=p.pok_name;
end$$
call TIPO_POKEMON('bulbasaur');
call TIPO_POKEMON('charmander');
call TIPO_POKEMON('charizard');
call TIPO_POKEMON('squirtle');


