#include<iostream>
using namespace std;

class Demo
{
    public:
        int A,B;
        static int X,Y;

        Demo()
        {
            //Initialization of non static characteristics
            A = 0;
            B = 0;
        };

        void fun()
        {
            cout<<"Inside non static function fun\n";
            cout<<"Value of A : "<<this->A<<"\n";          //the obj that calling its A
            cout<<"Value of B : "<<this->B<<"\n";          ////the obj that calling its B
            cout<<"Value of X : "<<X<<"\n";
            cout<<"Value of Y : "<<Y<<"\n";
        }

        static void Gun()
        {
            cout<<"Inside Static function Gun\n";
            cout<<"Value of X : "<<X<<"\n";
            cout<<"Value of Y : "<<Y<<"\n";
        }

};
//Initialising static characteristics
int Demo :: X = 10;
int Demo :: Y = 20;

int main()
{
    Demo::Gun();
    Demo obj;

    obj.fun();      //fun(&obj)
    obj.Gun();      //Avoid kara 

    return 0;
}