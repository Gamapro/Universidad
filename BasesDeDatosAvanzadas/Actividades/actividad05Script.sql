
use invoicing;

select payment_method, sum(amount) from payment_methods pm
join payments p on pm.id = p.payment_method
group by payment_method with rollup;

select name, sum(amount) from payment_methods pm
join payments p on pm.id = p.payment_method
group by payment_method with rollup
order by payment_method desc;



use store;

select id, first_name, last_name, birth_date, concat(timestampdiff(year, birth_date, CURDATE()), ' años') age from customers;



use invoicing;

select id, number, client_id, invoice_total, payment_total,
date_format(invoice_date, "%d %M %Y") invoice_date, 
date_format(due_date, "%d %M %Y") due_date, 
date_format(payment_date, "%d %M %Y") payment_date, 
concat(datediff(payment_date, invoice_date),' dias') as payment_done from invoices where payment_date is not null;



use store;

select concat(first_name, ' ', last_name) as name, if(phone is null, 'Desconocido', phone) as phone from customers;
