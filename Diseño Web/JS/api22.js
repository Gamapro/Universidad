let request = new XMLHttpRequest();
const url = 'https://dummy.restapiexample.com/api/v1/employees ';
request.open('GET', url);
request.onload = () => {
    let obj = JSON.parse(request.response);
    let div = document.createElement('div');
    let table = document.getElementById('tabla');
    obj.data.forEach(register => {
        div.innerHTML = `<div class="row">
            <div class="col border border-info">${register.id}</div>
            <div class="col border border-info">${register.employee_name}</div>
            <div class="col border border-info">${register.employee_age}</div>
            <div class="col border border-info">${register.employee_salary}</div>
        </div>`;
        table.appendChild(div.firstElementChild);
    });
}
request.send();