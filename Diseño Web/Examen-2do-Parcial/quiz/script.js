let questions = [
    {
        question: "¿Que lenguaje es usado en desarrollo WEB?",
        answers: { 1: 'Javascript', 2:"Java", 3:"C++", 4:"Python"},
        correct: 1 
    },
    {
        question: "Cual de los siguientes es un lenguaje de bajo nivel",
        answers: { 1: 'Pascal', 2:"Ensamblador", 3:"Perl", 4:"Fortran"},
        correct: 2 
    },
    {
        question: "Javascript es un lenguaje compilado",
        answers: { 1: 'Verdadero', 2:'Falso'},
        correct: 2 
    },
    {
        question: "C++ es un lenguaje compilado",
        answers: { 1: 'Verdadero', 2:'Falso'},
        correct: 1 
    },
    {
        question: "Lenguaje frecuentemente usado en microcontroladores",
        answers: { 1: 'Ruby', 2:'Python', 3:'Cobol', 4:'C'},
        correct: 4 
    },
    {
        question: "Programar puede ser estresante",
        answers: { 1: 'Verdadero', 2:'Falso'},
        correct: 1 
    },
    {
        question: "Mejor complejidad para ordenar un arreglo de numeros",
        answers: { 1: 'O(logn)', 2:'O(n^2)', 3:"O(nlogn)"},
        correct: 3
    },
    {
        question: "Forma mas eficiente en espacio de representar un grafo",
        answers: { 1: 'Lista de ejes', 2:'Lista de adjacencia', 3:"Matriz de adjancecia"},
        correct: 1 
    },
    {
        question: "Forma mas eficiente en complejidad de representar un grafo",
        answers: { 1: 'Lista de ejes', 2:'Lista de adjacencia', 3:"Matriz de adjancecia"},
        correct: 3
    },
    {
        question: "Mejor clase de programacion",
        answers: { 1: 'Web', 2:'La de arriba', 3:"Esta no es", 4:"Derecho no jaja"},
        correct: 1 
    }
]
let questionIdx;
let selectAnswer;
let aciertos;

function fillQuestionBox(){
    // remove last div
    document.getElementById("question-box").remove();
    // create new question div
    let div = document.createElement("div");
    div.className = "div-box";
    div.id = "question-box";
    let qst = document.createElement("div");
    qst.innerHTML = "<br> Pregunta " + (questionIdx+1) + "<br><br>" + 
        questions[questionIdx].question + "<br><br>" 
    ;
    div.appendChild(qst);
    // add answer options
    for(const [key, value] of Object.entries(questions[questionIdx].answers)) {
        let x = document.createElement("div");
        x.className = "boton-div"
        x.innerHTML = value;
        x.onclick = () => select(key, div);
        div.appendChild(x);
    }
    // add next question button
    let nextQuest = document.createElement("div");
    nextQuest.className = "next-box";
    nextQuest.innerHTML = "Siguiente pregunta";
    nextQuest.onclick = () => nextQuestion();
    div.appendChild(nextQuest);    
    document.body.appendChild(div);
    return;
}

function nextQuestion(){
    if(selectAnswer == -1){
        alert("Primero seleccione una respuesta! :D");
        return;
    }
    if(selectAnswer == questions[questionIdx].correct) aciertos++;
    questionIdx++;
    selectAnswer = -1;
    if(questionIdx == questions.length){
        showResults();
    }else{
        fillQuestionBox();
    }
    return;
}

function showResults(){
    // remove last div
    document.getElementById("question-box").remove();
    // create new question div
    let div = document.createElement("div");
    div.className = "div-box";
    div.id = "question-box";
    div.innerHTML = "Felicidades! Tu puntuación es: "+aciertos+'/'+
    questions.length;
    document.body.appendChild(div);
    return;
}

function select( key, div){
    selectAnswer = key;
    const bts = div.querySelectorAll(".boton-div, .selected-boton-div");
    for(let i = 0 ; i < bts.length; i++){
        if( i+1 == key ) bts[i].className = "selected-boton-div";
        else             bts[i].className = "boton-div";
    }
    return;
}

function rstVals(){
    questionIdx = 0;
    aciertos = 0;
    selectAnswer = -1;
    return;
}

function start(){
    let ant = document.getElementById("question-box");
    if( ant != null) ant.remove();
    rstVals();
    let div = document.createElement("div");
    div.className = "start";
    div.id = "question-box";
    div.innerHTML = "Click para empezar!";
    div.onclick = () => fillQuestionBox();
    document.body.appendChild(div);
    return;
}

rstVals();