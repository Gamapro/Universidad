
function generateTable(current = 0){
    let cosas = JSON.parse(localStorage.cosas);
    let n = cosas.length;
    console.log(cosas);

//<button type="button" data-bs-target="#indexCarousel" data-bs-slide-to="0" class="active"></button>
//                    <button type="button" data-bs-target="#indexCarousel" data-bs-slide-to="1"></button>

    for(let idx = 0, i = 0; i < 3; i++){

        let div = document.createElement("div");
        if(i == current) div.className = "carousel-item active row";
        else div.className = "carousel-item row";
        document.getElementById("insideCar").appendChild(div);

        let but = document.createElement("div");
        if(i==current)but.innerHTML= `<button type="button" 
        data-bs-target="#indexCarousel" data-bs-slide-to="${i}" class="active"></button>`;
        else but.innerHTML= `<button type="button" 
        data-bs-target="#indexCarousel" data-bs-slide-to="${i}" ></button>`;
        document.getElementById("buts").appendChild(but);

        for(let k = 0; k < 2; k++){
            let div2 = document.createElement("div");
            div2.className = "row";

        for(let j = 0; j < 2; j++, idx++){
        
            let product = cosas[idx];
            let cosa = document.createElement("div");
            cosa.innerHTML = `
                <div class="col">
                    <div class="card mb-5 text-center pb-3">
                        <div class="card-header bg-dark text-light fs-5 fw-dark">
                            ${product.nombre}
                        </div><br>
                        <p>Precio: \$${product.costo}</p>
                        <div><button class="btn btn-outline-warning" onclick="update(${idx},${i})">Editar</button></div>
                    </div>
                </div>
            `;
            div2.appendChild(cosa.firstElementChild);
        }
            div.appendChild(div2)
        }
    }
}

function update(idx,current) {
    let nuevo = parseInt(prompt("Nuevo precio"));
    if (!nuevo) {
        alert("Intente otra vez");
        return;
    }
    let products = JSON.parse(localStorage.cosas);
    products[idx].costo = nuevo;
    localStorage.setItem("cosas", JSON.stringify(products));
    document.getElementById("insideCar").innerHTML = "";
    document.getElementById("buts").innerHTML = "";
    generateTable(current);
}

generateTable(0);
