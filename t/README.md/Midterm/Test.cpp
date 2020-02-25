#include <iostream>
#include <cstddef>
#include <string>
using namespace std;

class Box
{
    int width, height; int * array;

public:
    int x=0;
    Box() : width(), height(){
        array = new int [200];
        cout<<"A"<<endl;
    }
    
    Box(const Box& b): width (b.width), height(b.height){
        array = new int[200];
        std::copy(b.array, b.array+200, array);
        cout<<"B"<<endl;
    }

    Box(Box&& b): 
        width(std::move(b.width)), height(std::move(b.height)){
            array = b.array;
            b.array = nullptr;
            cout<<"C"<<endl;
        }
    
    ~Box(){
        delete[] array;
        cout<<"D"<<endl;
    }

    Box& operator = (const Box& b){
        width = b.width; height = b.height;
        std::copy(b.array, b.array+200, array);
        cout<<"E"<<endl;
        return *this;
    }

    Box& operator = (Box&& b){
        width = b.width; height = b.height;
        delete[] array;
        array = b.array;
        b.array = nullptr;
        cout<<"I am in F"<<endl;
        cout<<"F"<<endl;
        cout<<"I am in *This"<<endl;
        return *this;
    }
};
    Box BoxReturn(void){
        Box b;
        cout<<"I am In BoxReturn"<<endl;
        return b;
    }

    int IntReturn(Box b){
        return b.x;
    }


int main(){
    cout<<"Box b1,b2"<<endl;
    Box b1, b2;
    cout<<"Box b3 = b1"<<endl;
    Box b3 = b1;
    cout<<"b2 = b1"<<endl;
    b2 = b1;
    cout<<"Box b4 = std::move(b2)"<<endl;
    Box b4 = std::move(b2);
    cout<<"b4 = std::move(b3)"<<endl;
    b4 = std::move(b3);
    cout<<"b4 = BoxReturn()"<<endl;
    b4 = BoxReturn();
    cout<<"int x = IntReturn (b1)"<<endl;
    int x = IntReturn (b1);
     cout<<"return 0"<<endl;
    return 0;
};