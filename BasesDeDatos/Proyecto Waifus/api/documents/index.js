const express = require("express");
const bodyParser = require("body-parser");
const app = express();

app.use(bodyParser.json());

app.use(function(req, res, next) {
    res.header("Access-Control-Allow-Origin", "*");
    res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
    next();
});

const configsql = {
    user:       'waifus',       // 'apicall',
    password:   'waifus',       // '12345',
    server: 'localhost',
    database: 'waifus',         // 'AnimeCharacters' ,
    options: {
        trustedConnection: true,
        encrypt: true,
        enableArithAbort: true,
        trustServerCertificate: true
    }
};

app.get('/', function(request, response){
    response.send("Hola api");
});

app.listen(3000, () => {
    console.log("Servidor iniciado en puerto 3000");
});

app.get('/byname', function(request, response){
    console.log("request");
    let name = request.query.name;

    var sql = require("mssql");

    sql.connect(configsql, function(err){
        if(err) console.log(err);

        var sqlrequest = new sql.Request();

        var querystring = "SELECT c.id, c.Name as Name, s.name as Serie, c.displayPicture as img FROM Characters c JOIN Series s ON s.id = c.seriesId WHERE c.name like '%"+name+"%'";

        sqlrequest.query(querystring, function(err, recordset){
            if(err) console.log(err);
            response.send(recordset);
        });
    });
});


app.get('/byserie', function(request, response){
    console.log("request");
    let name = request.query.name;

    var sql = require("mssql");

    sql.connect(configsql, function(err){
        if(err) console.log(err);

        var sqlrequest = new sql.Request();

        var querystring = "SELECT c.id, c.Name as Name, s.name as Serie, c.displayPicture as img FROM Characters c join series s on s.id = c.seriesId WHERE s.name like '%" + name + "%'"

        sqlrequest.query(querystring, function(err, recordset){
            if(err) console.log(err);
            response.send(recordset);
        });
    });
});

app.get('/bytags', function(request, response){
    console.log("request");
    let tags = request.query.tags.split(" ");

    var sql = require("mssql");

    sql.connect(configsql, function(err){
        if(err) console.log(err);

        var sqlrequest = new sql.Request();

        var querystring = "SELECT c.id, c.Name as Name, s.name as Serie, c.displayPicture as img FROM Characters c JOIN CharactersTags ct ON ct.idCharacter = c.id JOIN Tags t ON t.id = ct.idTag JOIN Series s ON s.id = c.seriesId WHERE ";

        for(let i = 0; i < tags.length; i++){
            if(i > 0) querystring += " or ";
            querystring += "t.name like '%"+tags[i]+"%'"
        }

        sqlrequest.query(querystring, function(err, recordset){
            if(err) console.log(err);
            response.send(recordset);
        });
    });
});

app.get('/byid', function(request, response){
    console.log("request");
    let id = request.query.id;

    var sql = require("mssql");

    sql.connect(configsql, function(err){
        if(err) console.log(err);

        var sqlrequest = new sql.Request();

        var querystring = ` SELECT c.id, c.Name as Name, s.name as Serie, c.displayPicture as img, c.birthday_day, c.birthday_month, c.birthday_year, c.age, c.weight, c.description, c.alternative_name as altName, cre.name as Creator 
                            FROM Characters c JOIN Series s ON s.id = c.seriesId 
                            JOIN Creators as cre ON cre.id = c.creatorId 
                            WHERE c.id=`+id;

        sqlrequest.query(querystring, function(err, recordset){
            if(err) console.log(err);
            response.send(recordset);
        });
    });
});

app.get('/tagsByid', function(request, response){
    console.log("request");
    let id = request.query.id;

    var sql = require("mssql");

    sql.connect(configsql, function(err){
        if(err) console.log(err);

        var sqlrequest = new sql.Request();

        var querystring = ` select t.name from Tags t
                            join CharactersTags ct on ct.idTag = t.id
                            where ct.idCharacter = `+id;

        sqlrequest.query(querystring, function(err, recordset){
            if(err) console.log(err);
            response.send(recordset);
        });
    });
});

app.get('/topLikes', function(request, response){
    console.log("request");

    var sql = require("mssql");

    sql.connect(configsql, function(err){
        if(err) console.log(err);

        var sqlrequest = new sql.Request();

        var querystring = ` select top 20 count(name) Cont, name Tag from CharactersTags ct 
                            join Tags tg on ct.idTag = tg.id 
                            group by name 
                            order by cont desc`;

        sqlrequest.query(querystring, function(err, recordset){
            if(err) console.log(err);
            response.send(recordset);
        });
    });

});

app.get('/randomTags', function(request, response){
    console.log("request");

    var sql = require("mssql");

    sql.connect(configsql, function(err){
        if(err) console.log(err);

        var sqlrequest = new sql.Request();

        var querystring = ` select top 10 count(name) Cont, name Tag from CharactersTags ct
                            join Tags tg on ct.idTag = tg.id
                            group by name
                            order by NEWID()`;

        sqlrequest.query(querystring, function(err, recordset){
            if(err) console.log(err);
            response.send(recordset);
        });
    });

});


app.get('/global', function(request, response){
    console.log("request");
    let name = request.query.name;

    var sql = require("mssql");

    sql.connect(configsql, function(err){
        if(err) console.log(err);

        var sqlrequest = new sql.Request();

        var querystring = ` select c.id, c.Name as Name, s.name as Serie, c.displayPicture as img 
                            from Characters c
                            join Series s on s.id = c.seriesId
                            WHERE c.name like '%${name}%' or s.name like '%${name}%' `;
        
        sqlrequest.query(querystring, function(err, recordset){
            if(err) console.log(err);
            response.send(recordset);
        });
    });
});
