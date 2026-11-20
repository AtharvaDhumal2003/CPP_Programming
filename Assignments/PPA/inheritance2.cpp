#include <iostream>

using namespace std;

// Parent class
class Demo
{
    public:
        int A, B;

        Demo()
        {
            A = 11;
            B = 21;
            cout<<"Inside Demo constructor."<<"\n";
        }

        ~Demo()
        {
           cout<<"Inside Demo destructor."<<"\n"; 
        }

        void fun()
        {
            cout<<"Inside fun of Demo"<<"\n";
        }
};


class Hello 
{
    public:
        
        int X, Y;

        Hello()
        {
            X = 51;
            Y = 101;
            cout<<"Inside Hello constructor."<<"\n";
        }

        ~Hello()
        {
          cout<<"Inside Hello destructor."<<"\n";  
        }

        void gun()
        {
            cout<<"Inside gun of Hello"<<"\n";
        }
};

class PPA : public Hello, public Demo           //this matters for constructor sequence
{
    public:
        int I, J;
        PPA()
        {
            I = 111;
            J = 121;
            cout<<"Inside PPA constructor."<<"\n";
        }
        ~PPA()
        {
            cout<<"Inside PPA destructor."<<"\n";   
        }

        void sun()
        {
            cout<<"Inside sun of PPA."<<"\n";
        }
};

int main()
{
    cout<<"Inside main"<<"\n";

    cout<<"Size of Demo : "<<sizeof(Demo)<<"\n";    //8
    cout<<"Size of Hello : "<<sizeof(Hello)<<"\n";  //8
    cout<<"Size of PPA : "<<sizeof(PPA)<<"\n";      //24

    PPA pobj;

    pobj.fun();
    pobj.gun();
    pobj.sun();

    cout<<pobj.A<<"\n"; //11
    cout<<pobj.B<<"\n"; //21
    cout<<pobj.X<<"\n"; //51
    cout<<pobj.Y<<"\n"; //101
    cout<<pobj.I<<"\n"; //111
    cout<<pobj.J<<"\n"; //121

    cout<<"End of main"<<"\n";

    return 0;
}