#include<iostream>

using namespace std;

class Demo
{
    public:
    int No1;
    int No2;

    void fun()
    {
        cout<<"Inside fun.\n";
    }
};

//Demo obj1;
//obj1.No1 = 10;error here i am changing 0 to 10 i.e action which should be inside function.
//obj1.No2 = 20;error 
//Demo obj1 = {10,20}; right .here while creating it is set to 10 not default 0.

int main()
{
    Demo obj1; //auto storage class 8 bytes allocated
    Demo obj2; //auto storage class 8 bytes allocated

    cout<<"size of object : "<<sizeof(obj1)<<"\n";
    cout<<"size of object : "<<obj2.No1<<"\n";

    obj1.No1 = 10;
    obj1.No2 = 20;

    obj2.No1 = 30;
    obj2.No2 = 40;

    obj1.fun();
    obj2.fun();

    cout<<obj1.No2<<"\n";
    
    return 0;
}