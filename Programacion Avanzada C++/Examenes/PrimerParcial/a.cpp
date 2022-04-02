#include <iostream>
#include <string>
using namespace std;

int target,n;

int main(){
    cout<<"Ingresa el numero de datos: ";
    cin>>n;
    int arr[n];
    cout<<"Ingresa los datos: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Ingresa el target: ";
    cin>>target;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j) continue;
            if(arr[i] + arr[j] == target){
                cout<<"Target localizado en indices "<<i<<" y "<<j<<".\n";
                return 0;
            }
        }
    }

    cout<<"Target no localizado.\n";

}
