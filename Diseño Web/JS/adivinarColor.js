
let colors = [];
let n_colors = 6
let correcto = 0;
let ya = false;

function resetColors(){
    colors = [];
    for( let i = 0; i < n_colors; i++){
        let r = Math.floor(Math.random() * 256);
        let g = Math.floor(Math.random() * 256);
        let b = Math.floor(Math.random() * 256);
        colors.push([r,g,b]);
    }
    return;
}

function drawCircles(){
    ya = false;
    resetColors();
    document.getElementById("par").innerHTML = "";
    correcto = Math.floor(Math.random() * 6);
    var canvas = document.getElementById("Colores");
    let contexto = canvas.getContext("2d");
    contexto.clearRect(0, 0, canvas.width, canvas.height);
    for( let i = 0; i < n_colors; i++){
        var radio = 50;
        let dt = radio*i*3;
        var x = 100 + dt, y = 100;
        contexto.beginPath();
        contexto.arc(x,y,radio,0,2*Math.PI);            
        contexto.stroke();
        let r = colors[i][0];
        let g = colors[i][1];
        let b = colors[i][2];
        rgbColor = 'rgb('+r+','+g+','+b+')';
        contexto.fillStyle = rgbColor;
        contexto.fill();
        if(correcto == i){
            document.getElementById("guess").innerHTML = 
            '('+r+', '+g+', '+b+')';
        }
    }
    return;
}

function addLineToDoc(cual){
    if(ya == true) return;
    let text = "";
    ya = true;
    if(cual == correcto+1) text = "Correcto!";
    else text = "Incorrecto. El color correcto es "+(correcto+1);
    document.getElementById("par").innerHTML = text;
    // let p = document.createElement("p");
    // let text = document.createTextNode("dogo");
    // p.appendChild(text);
    // var element = document.getElementById("new");
    // element.appendChild(p);
    // let p = document.getElementById("par");
    // p.
    return;
}