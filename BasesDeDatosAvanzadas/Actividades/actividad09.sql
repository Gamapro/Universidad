
use invoicing;

drop procedure if exists get_payments;
DELIMITER $$
create procedure get_payments(payment_id int, client_id int)
begin
	select * from clients c 
    join payments p on c.id = p.client_id
    where c.id = client_id and p.id = payment_id;
end$$
DELIMITER ;
call get_payments(1,1);


drop procedure if exists get_unpayed_invoices_from_client;
DELIMITER $$
create procedure get_unpayed_invoices_from_client(
	client_id int -- , out invoices_count int, out invoices_total decimal(9,2)
)
begin
	select c.id, c.name, count(1) conteo, sum(invoice_total) invoices_total_sum 
    -- into invoices_count, invoices_totalget_unpayed_invoices_from_clientget_unpayed_invoices_from_client
    from clients c 
    join invoices inv on c.id = inv.client_id
    where c.id = client_id and payment_total = 0
    group by c.id;
end$$
DELIMITER ;
call get_unpayed_invoices_from_client(3);




drop procedure if exists get_risk_factor;
DELIMITER $$
create procedure get_risk_factor()
begin
	select (5*sum(inv.invoice_total)/count(*)) as risk from invoices inv;
end$$
DELIMITER ;
call get_risk_factor();


drop procedure if exists get_risk_factor;
DELIMITER $$
create procedure get_risk_factor()
begin
	declare risk_factor decimal(9,2) default 0;
    declare invoices_total decimal(9,2);
    declare invoices_count int;
	select sum(inv.invoice_total), count(*) as risk 
    into invoices_total, invoices_count
    from invoices inv;
end$$
DELIMITER ;
call get_risk_factor();

-- variables locales y de sesion
-- create function funcion()
-- returns integer
-- deterministic
-- reads sql data
-- modifies sql data

DELIMITER $$
create function get_risk_factor_for_client(client_id int)
returns decimal
reads sql data
begin
	declare risk_factor decimal(9,2) default 0.0;
    declare invoices_count int default 0;
    declare invoices_total decimal(9,2) default 0.0;
    select sum(inv.invoice_total), count(*) as risk 
    into invoices_total, invoices_count
    from invoices inv
    where client_id = inv.id;
    set risk_factor = invoices_total/invoices_count;
    return risk_factor;
end $$
DELIMITER ;
select id, name, get_risk_factor_for_client(id) from clients;
