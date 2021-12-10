function showQuery(obj){
    if(obj == undefined) return;
    let data = obj.recordset;

    let cardgroup = document.getElementById("cardgroup");

    console.log(data[0]);

    for(let i=0; i < data.length; i++){
        let div = document.createElement('div');

        div.classList.add("d-flex");
        div.classList.add("col");
        div.innerHTML = `
        <div class="card mx-1 my-3" style="width: 18rem;">
            <img src="archive/${data[i].img}" class="card-img-top img-thumbnail" alt="archive/dificultadesTecnicas.jfif">
            <div class="card-body">
                <h5 class="card-title">`+ data[i].Name +`</h5>
                <p class="card-text"> Serie: `+data[i].Serie+`</p>
                <button onclick="popup(`+data[i].id+`)" id="`+data[i].id+`" class="btn btn-dark text-info" data-bs-toggle="modal" data-bs-target="#modal1">Detalles</button>
            </div>
        </div>
        `;
        cardgroup.appendChild(div);
    }
}

function strDate(a,b,c){
    s = "";
    if(a == null || a == "") s+="--";
    else s+=a;
    s+="/";
    if(b == null || b == "") s+="--";
    else s+=b;
    s+="/";
    if(c == null || c == "") s+="----";
    else s+=c;
    return s;
}

function noNullHandle(a){
    if(a == null || a == "") return "--";
    else return a;
}

function popup(id){

    let requestname = new XMLHttpRequest();
    requestname.open('GET', "http://localhost:3000/byid?id="+id, true)
    requestname.onload = function () {
        let obj = JSON.parse(requestname.response);
        let data = obj.recordset[0];
        document.getElementById("name").innerHTML = data.Name;
        document.getElementById("info").innerHTML =`
            <img src="/archive/`+data.img+`" class="img-fluid">
            <p>Serie: `+data.Serie+`</p>
            <p>Descripcion: `+data.description+`</p>
            <p>Nombre alternativo: `+noNullHandle(data.altName)+`</p>
            <p>Cumpleaños: `+strDate(data.birthday_day,data.birthday_month,data.birthday_year)+`</p>
            <p>Edad: `+noNullHandle(data.age)+`</p>
            <p>Altura: `+noNullHandle(data.height)+`</p>
            <p>Peso: `+noNullHandle(data.weight)+`</p>
            <p>Creador: `+data.Creator+`</p>
        `;
        console.log(id);
    }
    requestname.send();

    let requestname2 = new XMLHttpRequest();
    requestname2.open('GET', "http://localhost:3000/tagsByid?id="+id, true)
    requestname2.onload = function () {
        let obj = JSON.parse(requestname2.response);
        let data = obj.recordset;
        st = "";    
        console.log(data);
        for(let i = 0 ; i < data.length; i++){
            st += `<li class="p-1"><p> ${data[i]['name']} </p></li>`
        }
        if(st == "") st = `<li class="p-1"><p> No tags :( </p></li>`
        document.getElementById("tags").innerHTML = st;
    }
    requestname2.send();

}


function main(){
    let data = JSON.parse(localStorage.info);
    let name = data.text;
    let type = data.type;

    switch(type){
        case "name":
            let requestname = new XMLHttpRequest();
            requestname.open('GET', "http://localhost:3000/byname?name="+name, true)
            requestname.onload = function () {
                console.log(requestname.response);
                let obj = JSON.parse(requestname.response);
                showQuery(obj);
            }
            requestname.send()
        break;
        case "tag":
            let requesttags = new XMLHttpRequest();
            requesttags.open('GET', "http://localhost:3000/bytags?tags="+name, true)

            requesttags.onload = function () {
                let obj = JSON.parse(requesttags.response);
                showQuery(obj);
            }
            requesttags.send()
        break
        case "serie":
            let requestserie = new XMLHttpRequest();
            requestserie.open('GET', "http://localhost:3000/byserie?name="+name, true)

            requestserie.onload = function () {
                let obj = JSON.parse(requestserie.response);
                showQuery(obj);
            }
            requestserie.send()
        case "global":
            let requestglobal = new XMLHttpRequest();
            requestglobal.open('GET', "http://localhost:3000/global?name="+name, true)
            requestglobal.onload = function () {
                let obj = JSON.parse(requestglobal.response);
                showQuery(obj);
            }
            requestglobal.send()
        break;
        default:
            return;
    }
}


main();