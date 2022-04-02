use invoicing;

DELIMITER $$
create procedure get_algo()
begin
	select * from clients;
end$$
DELIMITER ;

call get_clientes();

DELIMITER $$
create procedure get_invoices()
begin
	select * from invoices;
end$$
DELIMITER ;

call get_invoices();
