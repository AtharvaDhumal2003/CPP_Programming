/////////////////////////////////////////////////////////////////////////////
//
//  Required Header File
//  
/////////////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
//  Function name:  Max
//  Description:    It use to find maximum number in given four numbers.
//  Input:          Integer
//  Author:         Atharva Sanjay Dhumal.
//  Date:           09/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template <class T>
T Max(T no1,T no2,T no3,T no4)
{
    T Max;

    if(no1 > no2 && no2 > no3 && no3 > no4)
    {
        Max = no1;
    }
    else if(no1 < no2 && no2 > no3 && no3 > no4)
    {
        Max = no2;
    }
    else if(no1 < no2 && no2 < no3 && no3 > no4)
    {
        Max = no3;
    }
    else
    {
        Max = no4;
    }

    return Max;
}

/////////////////////////////////////////////////////////////////////////////
//  
//  Entry Point Function for the application
//
/////////////////////////////////////////////////////////////////////////////
int main()
{
    int a = 10, b = 20,c = 30, d = 40;
    int iRet = Max(a,b,c,d);
    printf("Maximum number is:%d\n",iRet);

    float Z= 10.9f,A = 4.6f,X = 3.5f,Y = 7.8f;
    float fRet =Max(X,Y,Z,A);
    printf("Maximum number is:%f\n",fRet);


    return 0;
}
////////////////////////////////////////////////////////////////////////////////////
//Maximum number is:40
//Maximum number is:10.900000
////////////////////////////////////////////////////////////////////////////////////

