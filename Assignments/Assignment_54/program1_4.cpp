/////////////////////////////////////////////////////////////////////////////
//
//  Required Header File
//  
/////////////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
//  Function name:  Reverse
//  Description:    It use to reverse the given array.
//  Input:          Integer
//  Author:         Atharva Sanjay Dhumal/
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

    cout<<"Reversed array\n";
    for(i = 0; i < iSize;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";

}

/////////////////////////////////////////////////////////////////////////////
//  
//  Entry Point Function for the application
//
/////////////////////////////////////////////////////////////////////////////
int main()
{
    int arr [] = {12,13,11,14,15};
    Reverse(arr,5);

    float brr[] = {10.0,3.7,9.8,8.7,11.4,13.7};
    Reverse(brr,6);

    char crr[] = {'A','B','C','D','E','F','G'};
    Reverse(crr,7);

    return 0;
}
////////////////////////////////////////////////////////////////////////////////////
//Reversed array
//15      14      11      13      12
//Reversed array
///13.7    11.4    8.7     9.8     3.7     10
//Reversed array
//G       F       E       D       C       B       A
////////////////////////////////////////////////////////////////////////////////////

