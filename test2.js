const y = 1;
var z = 2;
let x = myFunction(4, 3); // Function is called, return value will end up in x

function myFunction(a, b) {
  return a * b; // Function returns the product of a and b
}

function toCelsius(fahrenheit) {
  return (5 / 9) * (fahrenheit - 32);
}
document.getElementById("demo").innerHTML = toCelsius(77);
