
function validate(){
    let age = parseInt(document.getElementById("age").value);
    let name = document.getElementById("nombre1").value;
    if(name == ""){
        alert("Proporcione un nombre valido.");
        return;
    }
    if(isNaN(age)){ 
        alert("Proporcione una edad valida.");
        return;
    }else if(age < 18){
        alert("Necesita ser mayor de edad para enviar informacion.");
        return;
    }
    alert("Contacto enviado!");
    return;
}

function enable(){
    let div = document.getElementById("gridCheck");
    let bot = document.getElementById("botonSubmit");
    bot.className = "btn btn-primary" + 
    (div.checked ? "" : " disabled");
    return;
}

enable();