#include<iostream>
using namespace std;

class Demo
{
    public:
        int A,B;            //Non-Static characteristics
        static int X,Y;     //Static characteristics

    Demo()                  //Default constructor
    {
        //Initialization of non static charcteristics
        A = 0;
        B = 0;
    };
};
//Initialization of static charcterstics
int Demo :: X = 10;
int Demo :: Y = 20;

int main()
{
    cout<<"Value of X : "<<Demo::X<<"\n";           //Use this syntax always
    cout<<"value of Y : "<<Demo::Y<<"\n";           //use this syntax always

    Demo obj1;
    Demo obj2;

    cout<<"Value of A from obj1 is : "<<obj1.A<<"\n";
    cout<<"Value of A from obj2 is : "<<obj2.A<<"\n";

    obj1.A++;

    cout<<"Value of A from obj1 is : "<<obj1.A<<"\n";
    cout<<"Value of A from obj2 is : "<<obj2.A<<"\n";

    cout<<"Value of X from obj1 is : "<<obj1.X<<"\n";       //Avoid this syntax
    cout<<"Value of X from obj2 is : "<<obj2.X<<"\n";       //Avoid this syntax

    cout<<"size of classes object is : "<<sizeof(obj1)<<"\n";//8
    
    return 0;
}