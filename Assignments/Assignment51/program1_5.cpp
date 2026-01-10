/////////////////////////////////////////////////////////////////////////////
//
//  Required Header File
//  
/////////////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;//** */

/////////////////////////////////////////////////////////////////////////////
//  Function name:  Reverse
//  Description:    It use to reverse the given array.
//  Input:          int
//  Author:         Atharva Sanjay Dhumal.
//  Date:           09/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template <class T>
void Reverse(T * arr,int iSize)
{
    int i = 0, iNo = iSize-1;
    T temp;

    while(iNo > i)
    {
       temp = arr[i];
       arr[i]= arr[iNo];
       arr[iNo]=temp;
        
        i++;
        iNo--;
    }
}
/////////////////////////////////////////////////////////////////////////////
//  
//  Entry Point Function for the application
//
/////////////////////////////////////////////////////////////////////////////
int main()
{
    int arr[] = {10,20,30,10,30,40,10,40,10};
    int i = 0;

    cout<<"Original Array:\n";
    for(i = 0; i < 9;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";

    Reverse(arr,9);
    
    cout<<"Reversed Array:\n";
    for(i = 0; i < 9;i++)
    {
        cout<<arr[i]<<"\t";
    }

    return 0;
}
////////////////////////////////////////////////////////////////////////////////////
//Original Array:
//10      20      30      10      30      40      10      40      10
//Reversed Array:
//10      40      10      40      30      10      30      20      10
////////////////////////////////////////////////////////////////////////////////////

