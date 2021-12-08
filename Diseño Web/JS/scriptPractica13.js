alert("Hola Mundo :)");
console.log("soy la consola... para que debuguees agusto :)")
var variable ='a'
//comentario en linea
alert("linea de comentario :)");
/*bloque
    de
    comentario
    */
alert("bloque de comentario :)");
//tipos de variables
//Numéricas
var iva = 16; // variable tipo entero
console.log(iva)
var total = 234.65; // variable tipo decimal
console.log(total)
///Cadenas de texto
var msj = "Bienvenido a nuestro sitio web";
console.log(msj)
var nP = 'Producto ABC';
console.log(nP)
var texto1 = "Una frase con 'comillas simples' dentro";
console.log(texto1)
var texto2 = 'Una frase con "comillas dobles" dentro';
console.log(texto2)
 texto1 = 'Una frase con \'comillas simples\' dentro';
console.log(texto1)
 texto2 = "Una frase con \"comillas dobles\" dentro";
console.log(texto2)

Arrays
var dia1 = "Lunes";
var dia2 = "Martes";

var dia7 = "Domingo";

var dias = ["Lunes", "Martes", "Miércoles", "Jueves",  "Viernes", "Sábado", "Domingo"];
var diaSeleccionado = dias[0]; // diaSeleccionado =
console.log(diaSeleccionado);


var visible = true;
alert(!visible); // Muestra "false" y no "true“
var cantidad = 0;
vacio = !cantidad; // vacio = true
cantidad = 2;
vacio = !cantidad; // vacio = false
var mensaje = "";

// Bucles

dias = ['Lunes', 'Martes', 'Miercoles', 'Jueves', 'Viernes', 'Sabado', 'Domingo'];

for(let i = 0; i < 5; i++) {
    console.log(i + " " + "hola");
}

for(let i = 0; i < 7; i++) {
    console.log("dia " + dias[i]);
}