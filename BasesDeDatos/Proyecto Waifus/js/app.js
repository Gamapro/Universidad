
function search(){
    let field = document.getElementById("nameinput").value;
    if(field.length == 0){
        return;
    }

    let select = document.getElementById("select").value;

    localStorage.info = JSON.stringify({ 
        text:field, type:select 
    });

    window.location.replace(`results.html`);
}

function topPieChart(){

    let requestname = new XMLHttpRequest();
    requestname.open('GET', "http://localhost:3000/topLikes", true);
    requestname.onload = function () {
        let obj = JSON.parse(requestname.response);
        let data = obj.recordset;
        let labels = [];
        let dataValues = [];
        let colors = [];
        for(let i = 0 ; i < data.length; i++){
            labels.push(data[i]['Tag']);
            dataValues.push(data[i]['Cont']);
            colors.push("#" + ((1<<24)*Math.random() | 0).toString(16));
        }
        console.log(data);
        console.log(labels);
        console.log(dataValues);
        console.log(colors);
        var ctxP = document.getElementById("pieChart").getContext('2d');
        var myPieChart = new Chart(ctxP, {
        type: 'pie',
        data:{
            labels: labels,
            datasets: [{
            data: dataValues,
            backgroundColor: colors,
            hoverBackgroundColor: colors
            }]
        },
        options: {
            responsive: true
        }
        });    
    }
    requestname.send();
}

function randomRecomendationChart(){

    let requestname = new XMLHttpRequest();
    requestname.open('GET', "http://localhost:3000/randomTags", true);
    requestname.onload = function () {
        let obj = JSON.parse(requestname.response);
        let data = obj.recordset;
        let labels = [];
        let dataValues = [];
        let colors = [];
        for(let i = 0 ; i < data.length; i++){
            labels.push(data[i]['Tag']);
            dataValues.push(data[i]['Cont']);
            colors.push("#" + ((1<<24)*Math.random() | 0).toString(16));
        }
        console.log(data);
        console.log(labels);
        console.log(dataValues);
        console.log(colors);
        var ctx = document.getElementById('myChart').getContext('2d');
        var myChart = new Chart(ctx, {
            type: 'bar',
            data: {
                labels: labels,
                datasets: [{
                    label: '# of Votes',
                    data: dataValues,
                    backgroundColor: colors,
                    borderColor: colors,
                    borderWidth: 1
                }]
            },
            options: {}
        });
    }
    requestname.send();
}

topPieChart();
randomRecomendationChart();
