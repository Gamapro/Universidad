use invoicing;

select client_id, sum(invoice_total) as total_sales, count(*) as number_of_invoices
from invoices 
group by client_id;


