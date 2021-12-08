
async function getUniversities(){
    let name = document.getElementById("input").value;
    if(name == ""){
        alert("Introduzca un pais.");
        return;
    }
    // https://github.com/Hipo/university-domains-list/
    const response = await fetch(`http://universities.hipolabs.com/search?country=${name}`);
    // const response = await fetch(`http://universities.hipolabs.com/search?country=${name}`);
    const myJson = await response.json();
    console.log(myJson);
    let n = myJson.length;
    console.log(n);
    let table = document.getElementById("tabla");
    table.innerHTML = '';
    for(let idx = 0 ; idx < n;){
        let div = document.createElement("div");
        div.className = "row";
        let s = '' ;
        for(let i = 0; i < 4; i++, idx++){
            console.log(myJson[idx]);
            s += `
            <div class="col-sm-3 my-2">
                <div class="card h-100 p-2 border border-warning rounded border-5   
                    bg bg-dark text-light">
                    <div class="card-body">
                        <h5 class="card-title">${myJson[idx]['name']}</h5>
                        <p class="card-text">${myJson[idx]['alpha_two_code']} </p>
                    </div>
                    <div class="card-footer">
                    <a href="${myJson[idx]['web_pages'][0]}" class="btn btn-info"> Pagina web </a>
                    </div>
                </div>
            </div>
            `;
        }
        div.innerHTML = s;
        table.appendChild(div);
    }
    return;
}
