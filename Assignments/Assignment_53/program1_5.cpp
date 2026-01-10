/////////////////////////////////////////////////////////////////////////////
//
//  Required Header File
//  
/////////////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
//  Function name:  Replace
//  Description:    It use to check if given value is exist in the array if it
//                  exists the it replaces it with given newvalue.
//  Input:          Integer
//  Author:         Atharva Sanjay Dhumal.
//  Date:           09/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template <class T>
void Replace(T * arr,int iSize,T oldVal,T newVal)
{   
   int i = 0;
   bool bFlag =  false;

   
   cout<<"New array is: ";
   for(i = 0; i < iSize; i++)
   {
        if(arr[i] == oldVal)
        {
            bFlag = true;
            arr[i] = newVal;
        }
        cout<<arr[i]<<"\t";
   }
   cout<<"\n";

   if(bFlag == false)
   {
        cout<<"There is no such value in the array."<<"\n";
   }
}

/////////////////////////////////////////////////////////////////////////////
//  
//  Entry Point Function for the application
//
/////////////////////////////////////////////////////////////////////////////
int main()
{
    int i = 0;

    int arr [] = {10,20,30,40,50};
    Replace(arr,5,20,3);

    char crr[] = {'a','b','c','d'};
    Replace(crr,4,'c','e');
  
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////
//New array is: 10       3       30      40      50
//New array is: a        b       e       d
////////////////////////////////////////////////////////////////////////////////////

