



alert( document.getElementById('header').textContent );
document.getElementById('header').textContent = 'Header Modificadoooo';


function Lista() { 
    
    vec = ['marcelino', 'pan', 'y', 'vino']
    
    let lista = document.getElementById('lista');

    for (let i = 0; i < lista.children.length; i++) {
        lista.children[i].textContent = vec[i % vec.length];
    }

}