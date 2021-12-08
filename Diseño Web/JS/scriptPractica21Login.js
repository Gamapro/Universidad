function data() {
    localStorage.users = JSON.stringify({ 
        admin: "123", user: "123" 
    });
    localStorage.cosas = JSON.stringify([
        {   nombre: "Ramen",
            costo: 199 },
        {   nombre: "Sopa de tortilla",
            costo: 235 },
        {   nombre: "Quesadillas",
            costo: 5 },
        {   nombre: "Mandarinas",
            costo: 21 },
        {   nombre: "Sopa de macaco",
            costo: 1234 },
        {   nombre: "Pan de muerto",
            costo: 67 },
        {   nombre: "Camote",
            costo: 6 },
        {   nombre: "Pan de nata",
            costo: 32 },
        {   nombre: "Chaskas",
            costo: 6 },
        {   nombre: "Queso",
            costo: 222 },
        {   nombre: "Pan de pan",
            costo: 45 },
        {   nombre: "Chokokrispis",
            costo: 1 }
        ]);
}

function logIn() {
    user = document.getElementById("user").value;
    password = document.getElementById("password").value;
    users = JSON.parse(localStorage.users);
    if(!users.hasOwnProperty(user)) {
        alert("Usuario incorrecto");
        return;
    }
    if(users[user] != password) {
        alert("Contraseña incorrecta");
        return;
    }
    sessionStorage.user = user;
    window.location.replace(`practica21_${user}.html`);
}

data();