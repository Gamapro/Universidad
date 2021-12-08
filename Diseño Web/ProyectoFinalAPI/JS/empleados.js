
async function getEmploye(){
    const response = await fetch('https://randomuser.me/api/');
    const myJson = await response.json();
    return myJson.results[0];
}

async function generateTable(){
    let n = 8;
    let table = document.getElementById("tabla");
    table.innerHTML = '';
    for(let i = 0 ; i < n; i++){
        let x = await getEmploye();
        let y = await getEmploye();
        console.log(x);
        let div = document.createElement("div");
        div.className = "row d-flex justify-content-center my-1";
        let namex = x.name['title']+' '+x.name['first']+' '+x.name['last'];
        let namey = y.name['title']+' '+y.name['first']+' '+y.name['last'];
        div.innerHTML= `
        <div class="col-sm-5 my-3 ">
            <div class="card my-3 h-100 bg-dark border border-dark border-5">
                <img id="img-${(i*2)}" src="${x.picture['large']}"
                    class="img-thumbnail bg-warning card-img-top rounded mx-auto" 
                    alt="Responsive image">
                <div class="card-body by-5 bg-dark text-light m-0">
                    <h5 class="card-title">${namex}</h5>
                    <p class="card-text">Age: ${x['dob']['age']}</p>
                    <p class="card-text">Gender: ${x['gender']}</p>
                    <p class="card-text">Phone: ${x['phone']}</p>
                    <p class="card-text">Mail: ${x['email']}</p>
                </div>
            </div>
        </div>
        <div class="col-sm-5 my-3">
        <div class="card my-3 h-100 bg-dark border border-dark border-5">
        <img id="img-${(i*2)+1}" src="${y.picture['large']}"
            class="img-thumbnail bg-warning card-img-top rounded mx-auto" 
            alt="Responsive image">
        <div class="card-body by-5 bg-dark text-light m-0">
            <h5 class="card-title">${namey}</h5>
            <p class="card-text">Age: ${y['dob']['age']}</p>
            <p class="card-text">Gender: ${y['gender']}</p>
            <p class="card-text">Phone: ${y['phone']}</p>
            <p class="card-text">Mail: ${y['email']}</p>
        </div>
    </div>
        </div>  
        `;
        table.appendChild(div);
    }
    return;
}

generateTable();