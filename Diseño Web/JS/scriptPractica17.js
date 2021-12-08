

document.getElementById("parrafo").textContent = "Hola Mundo Lol";

var parrafos = document.getElementsByTagName("p");

alert(parrafos.length);

for(let i = 0 ; i < parrafos.length ; i++){
    alert(parrafos[i].textContent);
    var links = parrafos[i].getElementsByTagName('a');
    for(let j = 0 ; j < links.length; j++){
        console.log(links[j].textContent);
    }
}
