#include <iostream>
#include <thread>
#include <time>
using namespace std;

// Pointer function
void foo(){
    int a=0;
    while(1){
        cout<<"FOO thread "<<a++<<"\n";
    }
}

// Callable object
class thread_obj{
public:
    void correr(){
        cout<<"Thread using class\n";
    }
};

int main(){
   
   thread t1(foo); 
   //thread t2(thread_obj);

   t1.join();
   //t2.join();

}
