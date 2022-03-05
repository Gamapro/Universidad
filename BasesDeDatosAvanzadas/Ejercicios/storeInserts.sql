use store;

INSERT INTO `products` VALUES (1,'Tablet',70,8000.00);
INSERT INTO `products` VALUES (2,'Audifonos',49,1500.00);
INSERT INTO `products` VALUES (3,'Smartphone',38,12000.00);
INSERT INTO `products` VALUES (4,'Mouse ',90,600.00);
INSERT INTO `products` VALUES (5,'Teclado',94,800.00);
INSERT INTO `products` VALUES (6,'MousePad',14,200.00);
INSERT INTO `products` VALUES (7,'Lampara',98,500.00);
INSERT INTO `products` VALUES (8,'PC Gamer',26,14000.00);
INSERT INTO `products` VALUES (9,'Laptop',67,20000.00);
INSERT INTO `products` VALUES (10,'Smartwatch',6,4000.00);


INSERT INTO `shippers` VALUES (1,'DHL');
INSERT INTO `shippers` VALUES (2,'UPS');
INSERT INTO `shippers` VALUES (3,'FEDEX');
INSERT INTO `shippers` VALUES (4,'ESTAFETA');
INSERT INTO `shippers` VALUES (5,'AMAZON');


INSERT INTO `customers` VALUES (1,'Barbara','Lopez','1986-03-28','962-625-7744','CENTRAL PONIENTE NO 18','Aguascalientes','AG',2273);
INSERT INTO `customers` VALUES (2,'Ines','Gomez','1986-04-13','804-427-9456','CAMPANA NO. 1708','Baja California Nte','BC',947);
INSERT INTO `customers` VALUES (3,'Alfredo','Borges','1985-02-07','719-724-7869','RIO SALINAS NO. 1118','Baja California Sur','BS',2967);
INSERT INTO `customers` VALUES (4,'Amara','Limon','1974-04-14','407-231-8017',' AV AGUASCALIENTES SUR 217','Ciudad de México','CX',457);
INSERT INTO `customers` VALUES (5,'Clemente','Hernández','1973-11-07',NULL,'CIRCUITO ARCO SUR SN','Chihuahua','CH',3675);
INSERT INTO `customers` VALUES (6,'María ','García','1991-09-04','312-480-8498','REPUBLICA DE NICARAGUA Nº605','Puebla','PU',3073);
INSERT INTO `customers` VALUES (7,'Valeria','Martínez','1964-08-30','615-641-4759','50 Lillian Crossing','Queretaro','QT',1672);
INSERT INTO `customers` VALUES (8,'Sofia','Pérez','1993-07-17','941-527-3977','AZALEA NO. 709','San Luis','SL',205);
INSERT INTO `customers` VALUES (9,'Renata','Rodríguez','1992-05-23','559-181-3744',' RICARTE 580 INT 2','Sinaloa','SI',1486);
INSERT INTO `customers` VALUES (10,'Victoria','Sánchez','1969-10-13','404-246-3370','CALLE 3 NO. 41 NO. B','Zacatecas','ZA',796);



INSERT INTO `order_statuses` VALUES (1,'Procesada');
INSERT INTO `order_statuses` VALUES (2,'Enviada');
INSERT INTO `order_statuses` VALUES (3,'Entregada');



INSERT INTO `orders` VALUES (1,6,'2020-01-30',1,'Lorem Ipsum is simply dummy text of the printing and typesetting',NULL,NULL);
INSERT INTO `orders` VALUES (2,7,'2018-08-02',2,NULL,'2018-08-03',4);
INSERT INTO `orders` VALUES (3,8,'2017-12-01',1,NULL,NULL,NULL);
INSERT INTO `orders` VALUES (4,2,'2017-01-22',1,NULL,NULL,NULL);
INSERT INTO `orders` VALUES (5,5,'2017-08-25',2,'','2017-08-26',3);
INSERT INTO `orders` VALUES (6,10,'2018-11-18',1,'Aliquam erat volutpat. In congue.',NULL,NULL);
INSERT INTO `orders` VALUES (7,2,'2018-09-22',2,NULL,'2018-09-23',4);
INSERT INTO `orders` VALUES (8,5,'2018-06-08',1,'Mauris enim leo, rhoncus sed, vestibulum sit amet, cursus id, turpis.',NULL,NULL);
INSERT INTO `orders` VALUES (9,10,'2017-07-05',2,'Nulla mollis molestie lorem. Quisque ut erat.','2017-07-06',1);
INSERT INTO `orders` VALUES (10,6,'2018-04-22',2,NULL,'2018-04-23',2);


INSERT INTO `order_items` VALUES (1,4,4,600.00);
INSERT INTO `order_items` VALUES (2,1,2,8000.00);
INSERT INTO `order_items` VALUES (2,4,4,600.00);
INSERT INTO `order_items` VALUES (2,6,2,200.00);
INSERT INTO `order_items` VALUES (3,3,10,12000.00);
INSERT INTO `order_items` VALUES (4,3,7,12000.00);
INSERT INTO `order_items` VALUES (4,10,7,4000.00);
INSERT INTO `order_items` VALUES (5,2,3,1500.00);
INSERT INTO `order_items` VALUES (6,1,4,8000.00);
INSERT INTO `order_items` VALUES (6,2,4,1500.00);
INSERT INTO `order_items` VALUES (6,3,4,12000.00);
INSERT INTO `order_items` VALUES (6,5,1,800.00);
INSERT INTO `order_items` VALUES (7,3,7,12000.00);
INSERT INTO `order_items` VALUES (8,5,2,800.00);
INSERT INTO `order_items` VALUES (8,8,2,14000.00);
INSERT INTO `order_items` VALUES (9,6,5,200.00);
INSERT INTO `order_items` VALUES (10,1,10,8000.00);
INSERT INTO `order_items` VALUES (10,9,9,20000.00);


INSERT INTO `order_item_notes` (`note_id`, `order_Id`, `product_id`, `note`) VALUES ('1', '1', '2', 'nota ejemplo 1');
INSERT INTO `order_item_notes` (`note_id`, `order_Id`, `product_id`, `note`) VALUES ('2', '1', '2', 'nota ejemplo 2');

