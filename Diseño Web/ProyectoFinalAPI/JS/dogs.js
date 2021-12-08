
async function getImage(){
    const response = await fetch('https://dog.ceo/api/breeds/image/random');
    const myJson = await response.json();
    console.log(myJson);
    let div = document.getElementById("img");
    if(myJson.status != "success") div.src = "../Imgs/dificultadesTecnicas.jfif"
    else div.src = myJson.message;
    return;
}