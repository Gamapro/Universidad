Integración Node JS
SQL Server Configuration Manager:
	SQL Server Network Configuration
		Protocols for MSSQLSERVER
			Enable TCP/IP
	SQL Server Services
		SQL Server -> Restart
SQL Server Management
	Security 
		Logins -> New Login
			General
				SQL Server Authentication
				Uncheck enforce password policy
				Default database: Choose the database
			User Mapping
				Check the database
				Give reader and writer permissions
			Status 
				Grant	
				Enabled
			Ok
CMD
	Choose directory
	npm init -y
	npm install express --save
	npm install nodemon --save
	npm install mssql --save
	code .
VS Code
	package.json
		    "start": "node documents/api/index.js",
		    "dev": "nodemon documents/api/index.js"
	crear carpetas y file documents/api/index.js
	index.js 
		const express = require("express");
		const app = express();
		app.get('/', function(requets, response){
		    response.send("API desde NodeJS")
		});
		app.listen(3000, () => {
		    console.log("Servidor iniciado en puerto 3000");
		});
CMD
	Misma carpeta
	npm run dev
Browser
	localhost:3000
Postman
	Get
		http://localhost:3000/	
		http://localhost:3000/brand
		http://localhost:3000/brand?filter=maru