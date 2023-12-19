const express = require('express')
const mysql = require('mysql2')
const cors = require('cors')
const app = express()
const port = 8069

var con = mysql.createConnection({host: 'localhost',user:'alumnos',password: 'app.2023',database: 'gama'})

app.use(cors())
app.use(
    express.urlencoded(
        {extended: true}
    )
)

app.get('/buscar', (req,res) =>{
    con.connect(function(err){
        if(err) throw err;
        con.query("SELECT * FROM Peliculas", function(err, result, fields){
            if(err) throw err;
            console.log(result);
            res.send(result);
        });
    })
})

app.post('/guardar', (req, res) =>{
    con.connect(function(err){
        if(err) throw err;
        con.execute("insert into Peliculas (id, nivel, titulo, anio, votos) values (0, ?, ?, ?, ?)", 
            [req.body.nivel, req.body.titulo, req.body.anio, req.body.votos],
            function(err, result, fields){
                if(err) throw err;
                res.send(req.body);
        });
    })
})

app.post('/modificar', (req, res) =>{
    con.connect(function(err){
        if(err) throw err;
        con.execute("update Peliculas set nivel = ?, titulo = ?, anio = ?, votos = ? where id = ?", 
            [req.body.nivel, req.body.titulo, req.body.anio, req.body.votos, req.body.id],
            function(err, result, fields){
                if(err) throw err;
                res.send(req.body);
        });
    })
})

app.post('/borrar', (req, res) =>{
    var id = req.body.Id;
    id = id.replace('[', '');
    id = id.replace(']', '');
    con.connect(function(err){
        if(err) throw err;
        con.execute("delete from Peliculas where id = ?", 
            [id],
            function(err, result, fields){
                if(err) throw err;
                res.send(req.body);
        });
    });
    
})

app.post('/servicioweb', (req, res) => {
    res.send(req, params);
});

app.get('/', (req, res) => {
    res.send('Que onda prros')
});

app.listen(port, () => {
    console.log(`Example app listening at http://localhost:${port}`)
})