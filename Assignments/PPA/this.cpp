#include<iostream>
using namespace std;

class Demo
{
    public:
        int No1;
        int No2;

        Demo(int i, int j)
        {
            No1 = i;
            No2 = j;
        }

        void Fun(int A, int B)          //void Fun(Demo *this,int A , int B)
        {
            cout<<"Inside Fun : "<<this->No1<<"\n";
            cout<<"Inside Fun : "<<this->No2<<"\n";
            //Cout<<A<<"\n";
            //Cout<<B<<"\n";
        }

        void Gun(int A)             //void Gun(Demo *this,int A)
        {
            cout<<"Inside Gun : "<<this->No1<<"\n";
            cout<<"Inside Gun : "<<this->No2<<"\n";
            //Cout<<A<<"\n";
        }
};

int main()
{
    Demo obj1(11,21);   // here first memory allocated then control goes in parametarised constructor object2 or 1 gets No1 = 51 No2 = 101 
    Demo obj2(51,101);  // so objects created 

    obj1.Fun(10,20);    //Fun(&obj1,10,20)          //Fun(100,10,20)
    obj2.Gun(10);       //Gun(&obj2,10)             //Gun(200,10)      //here 10 we are passing to function it will use it it not goes
    // in no1 or no2 they are already created 10 is just parameter written to show first parameter

    return 0;
}

//Every c++ program internally converted into c