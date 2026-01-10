/////////////////////////////////////////////////////////////////////////////
//
//  Required Header File
//  
/////////////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
//  Function name:  SecondMax
//  Description:    It use find second maximum number in the array.
//  Input:          Integer
//  Author:         Atharva Sanjay Dhumal.
//  Date:           09/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template <class T>
T SecondMax(T * arr,int iSize)
{   
    T Max = 0;
    T Smax = 0;
    int i = 0;

    for(i = 0; i < (iSize);i++)
    {
        if(arr[i] > Max)
        {
            Max = arr[i];
        }
    }

    Smax = 0;

    for(i = 0; i < (iSize);i++)
    {
        if(arr[i] != Max)
        {
           if(arr[i] > Smax)
           {
                Smax = arr[i];
           }
        }
    }
 
    return Smax;

}

/////////////////////////////////////////////////////////////////////////////
//  
//  Entry Point Function for the application
//
/////////////////////////////////////////////////////////////////////////////
int main()
{
    int arr [] = {10,20,30,40,50};
    int iRet = SecondMax(arr,5);
    printf("Second maximum number is:%d\n",iRet);


    float brr[] = {10.0,3.7,9.8,8.7};
    float fRet = SecondMax(brr,4);
    printf("Second maximum number is:%f\n",fRet);

    double drr[] = {55.6667,33.6723,44.2312};
    double dRet = SecondMax(drr,3);
    printf("Second maximum number is:%f\n",dRet);

 
    
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////
//Second maximum number is:40
//Second maximum number is:9.800000
//Second maximum number is:44.231200
////////////////////////////////////////////////////////////////////////////////////

