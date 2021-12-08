
function chart(prob){
    var ctxP = document.getElementById("pieChart").getContext('2d');
    var myPieChart = new Chart(ctxP, {
    type: 'pie',
    data: {
        labels: ["Female", "Male"],
        datasets: [{
        data: [prob, 1-prob],
        backgroundColor: ["#F7464A", "#46BFBD"],
        hoverBackgroundColor: ["#FF5A5E", "#5AD3D1"]
        }]
    },
    options: {
        responsive: true
    }
    });
}

async function getPrediction(){
    let name = document.getElementById("input").value;
    if(name == ""){
        alert("Introduzca un nombre.");
        return;
    }
    const response = await fetch(`https://api.genderize.io/?name=${name}`);
    const myJson = await response.json();
    console.log(myJson);
    if(myJson.gender == 'male') chart(1 - myJson.probability);
    else chart(myJson.probability);
    return;
}

chart(0.5);