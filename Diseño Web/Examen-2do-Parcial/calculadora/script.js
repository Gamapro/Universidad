
let op = "";
let display = "";
let rst = true;

function resVals(){
    rst = true;
    op = "";
    display = "";
    return;
}

function add(val){
    op+=String(val);
    if(Number.isInteger(val) || val=='.'){
        if(rst == true) display = "";
        display+=String(val);
        rst = false;
    }
    else rst = true;
    if(display != '') document.getElementById("disp").innerHTML = display;
    else setDisplayZero();
    return;
}

function setDisplayZero(){
    document.getElementById("disp").innerHTML = '0';
    return;
}

function ev(){
    if(op == ''){ setDisplayZero();             
    }else{
        let val = eval(op) + "<br>";
        document.getElementById("disp").innerHTML = val;
        resVals();
    }
    return;
}

function reset(){
    resVals();
    setDisplayZero();
    return;
}