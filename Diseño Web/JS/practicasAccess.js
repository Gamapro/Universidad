
function load(){
    localStorage.password = JSON.stringify({ 
        password: "1234"
    });
    return;
}

function login(lang){
    let password = document.getElementById('password').value;
    document.getElementById('password').value = "";
    let pass = JSON.parse(localStorage.password);
    if(password != pass['password']){
        if(lang == 'es') alert("Contraseña incorrecta");
        if(lang == 'en') alert("Incorrect password");
        return;
    }
    if(lang == 'es') window.location.replace(`practicasAdmin.html`);
    if(lang == 'en') window.location.replace(`practicasEnAdmin.html`);
    return;
}

load();
