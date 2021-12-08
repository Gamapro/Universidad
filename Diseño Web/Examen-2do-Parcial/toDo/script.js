
function addToList( toDo ){
    if(event.key != 'Enter' || toDo.value == "") return;

    let div = document.createElement("div");
    let p = document.createElement("p");
    let text = document.createTextNode(toDo.value);
    toDo.value = '';

    div.className = "container";
    p.onclick = function(){ completed(this.parentElement) };
    p.oncontextmenu = function(event){ event.target.parentElement.remove(); };
    p.appendChild(text);
    div.appendChild(p);
    let element = document.getElementById("list");
    element.appendChild(div);
    return;
}

function completed(boton){
    const p = boton.querySelectorAll("p");
    p[0].style.color = "#7E00D6";
    p[0].className = "completed";
    return;
}

