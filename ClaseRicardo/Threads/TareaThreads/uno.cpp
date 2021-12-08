#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <time.h>
#include <stdlib.h>
using namespace std;

#define n_threads 2
const int n = 10;
thread t[n_threads];

void print_arr(int arr[], const int n, const string cual){
    cout<<cual<<" [";
    for(int i=0;i<n;i++){
        if(i)cout<<", ";
        cout<<arr[i];
    }
    cout<<"]\n";
}

void burbuja(int arr[], const int n){
    for(int i=1;i<n;i++){
        for(int j=i;j>0 && arr[j]<arr[j-1];j--){
            swap(arr[j],arr[j-1]);
            //print_arr(arr,n,"Bubble");
            //this_thread::sleep_for(chrono::milliseconds(500));
        }
    }
}

void merge(int arr[], const int l, const int m, const int r) {
   int i, j, k, nl, nr;
   nl = m-l+1; nr = r-m;
   int L[nl], R[nr];
   for(i = 0; i<nl; i++)
      L[i] = arr[l+i];
   for(j = 0; j<nr; j++)
      R[j] = arr[m+1+j];
   i = 0; j = 0; k = l;
   while(i < nl && j<nr) {
      if(L[i] <= R[j]) {
         arr[k] = L[i];
         i++;
      }else{
         arr[k] = R[j];
         j++;
      }
      k++;
   }
   while(i<nl) {
      arr[k] = L[i];
      i++; k++;
   }
   while(j<nr) { 
      arr[k] = R[j];
      j++; k++;
   }
}

void mergeSort(int arr[], int l, int r) {
    int m;
    if(l < r) {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
        //print_arr(arr,n,"MERGE");
        //this_thread::sleep_for(chrono::milliseconds(500));
    }
}

void mezclar(int arr[], int l, int r) { 
    mergeSort(arr,l,r);
    //this_thread::sleep_for(chrono::milliseconds(500));
}

int main(){
    srand (time(NULL));
    int arr_bubble[n], arr_merge[n];
    for(int i=0;i<n;i++){
        arr_bubble[i] = rand()%11;
        arr_merge[i] = rand()%11;
    }   
        
    t[0] = thread(burbuja, arr_bubble, n);
    t[1] = thread(mezclar, arr_merge, 0, n-1);
    
    t[0].join();
    t[1].join();
    
    print_arr(arr_merge,n,"MERGE FINAL");
    print_arr(arr_bubble,n,"BUBBL FINAL");
}

