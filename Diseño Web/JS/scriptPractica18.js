
const botones = document.getElementsByTagName('input');

for(let i = 0; i < botones.length; i++) {
    if(botones[i].hasAttribute('checked')) {
        alert('Boton '+ (i+1) + ' seleccionado.')
    }
}