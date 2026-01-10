/////////////////////////////////////////////////////////////////////////////
//
//  Required Header File
//  
/////////////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
//  Function name:  CheckSorted
//  Description:    It use to check if array is sorted or not.
//  Input:          Integer
//  Author:         Atharva Sanjay Dhumal.
//  Date:           09/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template <class T>
bool CheckSorted(T * arr,int iSize)
{
    bool bFlag = false;
    int i = 0;
    int iNo = 0;
    for(i = 0,iNo = 1; i < iSize;i++,iNo++)
    {
       if(arr[i] > arr[iNo])
       {
            bFlag = true;
            break;
       }
    }
    
    return bFlag;

}

/////////////////////////////////////////////////////////////////////////////
//  
//  Entry Point Function for the application
//
/////////////////////////////////////////////////////////////////////////////
int main()
{
    int arr [] = {10,20,30,40,50};
    bool bRet = CheckSorted(arr,5);

    if(bRet == true)
    {
        printf("Array is not sorted.\n");
    }
    else
    {
        printf("Array is sorted.\n");
    }


    float brr[] = {10.0,3.7,9.8,8.7};
    
    bool fRet = CheckSorted(brr,4);

    if(fRet == true)
    {
        printf("Array is not sorted.\n");
    }
    else
    {
        printf("Array is sorted.\n");
    }
    
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////
//Array is sorted.
//Array is not sorted.
////////////////////////////////////////////////////////////////////////////////////

