
function validate(lang){
    let age = parseInt(document.getElementById("age").value);
    let name = document.getElementById("nombre1").value;
    if(name == ""){
        if(lang == 'es') alert("Proporcione un nombre valido.");
        if(lang == 'en') alert("Choose a valid name.");
        return;
    }
    if(isNaN(age)){ 
        if(lang == 'es') alert("Proporcione una edad valida.");
        if(lang == 'en') alert("Choose a valid age.");
        return;
    }else if(age < 18){
        if(lang == 'es') alert("Debe ser mayor de edad para enviar un mensaje.");
        if(lang == 'en') alert("You must be over 18 to send a message.");
        return;
    }
    if(lang == 'es') alert("Mensaje enviado!");
    if(lang == 'en') alert("Message submited!");
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