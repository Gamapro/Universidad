alert("HOLAAAAAAAAAAAA")


// Arrays 

array = ['Pera', 'Manzana', 'Jamon', 'Jamaica']
array.push('Sandia');
console.log(array);
array.pop();
array.shift();
array.unshift('Caramelo');
array.push('Suika')
array.reverse();
console.log(array);

alert(array.join(' '));

// NaN

let a = 0, b = 0;

if(isNaN(a/b)){
    console.log("Division no definida");
}else{
    console.log("La division a/b = "+string(a/b));
}