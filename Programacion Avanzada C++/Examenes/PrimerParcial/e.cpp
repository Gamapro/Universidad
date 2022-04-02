#include <iostream>
#include <string>
using namespace std;

int n;

int main(){
    cout<<"Ingresa el numero de datos: ";
    cin>>n;
    int arr[n];
    int pos=0,neg=0,cero=0;
    cout<<"Ingresa los datos: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=1;i<n;i++){
        if(arr[i]-arr[i-1] > 0){
            pos++;
        }else if(arr[i]-arr[i-1] < 0){
            neg++;
        }else{
            cero++;
        }
    }

    if( (pos==0 && neg==0) || (pos > 0 && neg == 0) ||(pos == 0 && neg > 0)  ){
        cout<<"True\n";
    }else{   
        cout<<"False\n";
    }

}

