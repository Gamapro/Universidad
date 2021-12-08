#include <iostream>
#include <string>
using namespace std;

void mightGoWrong(){
    bool error = false; //true;
    bool error2 = true;
    if(error){
        throw 8;
    }
    if(error2){
       throw "Que esta pasando doctor garcia";
    }
}

int main(){
    try{
        mightGoWrong();
        int n;
        cin>>n;
        int arr[10];
        cin>>arr[n];
        cout<<arr[n]<<'\n';
    }catch(int e){
        cout<<"Error code: "<<e<<'\n';
    }catch(const char* e){
        cout<<e<<'\n';
    }
}
