
function generate() {
    let cart = JSON.parse(localStorage.carrito);
    let products = JSON.parse(localStorage.cosas);
    let dummmy = document.createElement("div");
    let total = 0;
    for(let i = 0; i < 10; i++) {
        if(cart[i] > 0) {
            // <div class="d-flex justify-content-center"></div>
            dummmy.innerHTML = `
            <div class="container m-auto">
            <div class="row m-auto">
                <div class="col d-flex justify-content-end m-auto">
                    <button class="btn btn-danger" 
                    onclick="removeElement(${i})">Cancelar</button>
                </div>
                <div class="col ">
                    <div class="fw-bold d-flex justify-content-center ">${
                        products[i].nombre
                    }</div>    
                    <div class="d-flex justify-content-center ">
                        Costo: \$${
                            products[i].costo
                        } Subtotal: \$${
                            products[i].costo * cart[i]
                            }
                    </div>                    
                </div>
                <div class="col">
                    <h3><span class="text-dark badge bg-warning ">Cantidad: ${cart[i]}</span></h3>
                </div>
               
            </div>
            </div>`;
            document.getElementById("compras").appendChild(dummmy.firstElementChild);
            total += products[i].costo * cart[i];
        }
    }
    dummmy.innerHTML = `
        <div>
            <div class="d-flex justify-content-center">
                <h3 class="mt-5 text-info text-end">Total: \$${total}</h2>
            </div>
            <div class="d-flex justify-content-center">
                <button class="btn btn-info" 
                onclick="buy()">Comprar</button>
            </div>
        </div>
        `;
    document.getElementById("total").appendChild(dummmy.firstElementChild);
}

function update() {
    document.getElementById("compras").innerHTML = "";
    document.getElementById("total").innerHTML = "";
    generate();
}

function removeElement(id) {
    let cart = JSON.parse(localStorage.carrito);
    cart[id] = Math.max(cart[id]-1, 0);
    localStorage.carrito = JSON.stringify(cart);
    alert("Producto eliminado!");
    update();
}

function buy() {
    localStorage.carrito = JSON.stringify(Array(10).fill(0));
    alert("Compra exitosa!");
    update();
}

generate();