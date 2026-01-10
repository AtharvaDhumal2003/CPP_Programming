/////////////////////////////////////////////////////////////////////////////
//
//  Required Header File
//  
/////////////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
//  Function name:  Search
//  Description:    It use Search given element in the array.
//  Input:          Integer
//  Author:         Atharva Sanjay Dhumal.
//  Date:           09/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template <class T>
bool Search(T * arr,int iSize,T Value)
{
    int i = 0;
    bool bFlag = false;

    for(i = 0; i < iSize;i++)
    {
       if(arr[i] == Value)
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
    bool iRet = Search(arr,5,40);
    if(iRet == true)
    {
        printf("Element is in the array.\n");
    }
    else
    {
      printf("Element not in the array.\n");  
    }

    float brr[] = {10.0,3.7,9.8,8.7};
    bool fRet = Search(brr,4,11.3f);

    if(fRet == true)
    {
        printf("Element is in the array.\n");
    }
    else
    {
      printf("Element not in the array.\n");  
    }
    

    return 0;
}
////////////////////////////////////////////////////////////////////////////////////
//Element is in the array.
//Element not in the array.
////////////////////////////////////////////////////////////////////////////////////

