/////////////////////////////////////////////////////////////////////////////
//
//  Required Header File
//  
/////////////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
//  Function name:  SecondMin
//  Description:    It use to copy the one array into another array.
//  Input:          Integer
//  Author:         Atharva Sanjay Dhumal.
//  Date:           09/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template <class T>
T SecondMin(T * arr,int iSize)
{   
    int i =0;
    T Min = arr[i];
    T Smin = 0;

    for(i = 0; i < iSize; i++)
    {
        if(arr[i] < Min)
        {
            Min = arr[i];
        }
    }

    Smin = arr[i];

    for(i = 0; i < iSize; i++)
    {
        if(arr[i] != Min)
        {
            if(arr[i] < Smin)
            {
                Smin = arr[i];
            }
        }
    }
    
    return Smin;
}

/////////////////////////////////////////////////////////////////////////////
//  
//  Entry Point Function for the application
//
/////////////////////////////////////////////////////////////////////////////
int main()
{
    int arr [] = {10,20,30,40,50};
    int iRet = SecondMin(arr,5);
    printf("Second minimum number is:%d\n",iRet);

    double drr[] = {55.6667,33.6723,44.2312};
    double dRet = SecondMin(drr,3);
    printf("Second minimum number is:%f\n",dRet);

    return 0;
}
////////////////////////////////////////////////////////////////////////////////////
//Second minimum number is:20
//Second minimum number is:44.231200
////////////////////////////////////////////////////////////////////////////////////

