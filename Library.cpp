//////////////////////////////////////////////////////////////////////////
//      Gerenalised Data structure library
/////////////////////////////////////////////////////////////////////////

/*
---------------------------------------------------------------------------------------------------------------------------
|Type                  Name of class for node                      Name of class for functionality     Status             |
---------------------------------------------------------------------------------------------------------------------------
|Singly Linear         SinglyLLLnode                               SinglyLLL                            Done              |
|Singly Circular       SinglyCLLnode                               SinglyCLL                            Done              |
|Doubly Linear         DoblyLLLnode                                DoblyLLL                             Done              |
|Doubly Circular       DoublyCLLnode                               DoublyCLL                            Done              |
---------------------------------------------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////
//      Singly linerlinklist using Generic Approach
/////////////////////////////////////////////////////////////////////
#pragma pack(1)

template<class T>
class SinglyLLLnode
{
   public: 
    T data;
    SinglyLLLnode<T> *next;

    SinglyLLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};

template<class T>
class SinglyLLL
{
    private:           
        SinglyLLLnode<T>* first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);    

};

template<class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Object of singlyLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      InsertFirst
//  Input:              Data of node
//  Output:             Nothing
//  Description:        Used to add node at first position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    SinglyLLLnode<T> *newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn -> next = this->first;
        this->first = newn;
    }

    this->iCount++;

}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      InsertLast
//  Input:              Data of node
//  Output:             Nothing
//  Description:        Used to add node at the last position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T> *newn = NULL;
    SinglyLLLnode<T> *temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)             
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
    }

    this->iCount++; 
}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      DeleteFirst
//  Input:              Nothing
//  Output:             Nothing
//  Description:        Used to delete node at the first position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> *temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first -> next == NULL)      
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first -> next;
        delete temp;

    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      DeleteLast
//  Input:              Nothing
//  Output:             Nothing
//  Description:        Used to delete node the at Last position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteLast()
{
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first -> next == NULL)     
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        SinglyLLLnode<T> *temp = NULL;

        temp = this->first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        delete temp -> next;
        temp -> next = NULL;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      Display
//  Input:              Nothing
//  Output:             Nothing
//  Description:        Used to display nodes in the linklist.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    temp = this->first;
    for(iCnt = 1; iCnt <= this->iCount;iCnt++)     
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      Count
//  Input:              Nothing
//  Output:             Nothing
//  Description:        Used to count elements in the linklist.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}


////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      InsertAtPos
//  Input:              Data of node and position
//  Output:             Nothing
//  Description:        Used to add node at given position position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertAtPos(T no,int pos)
{
    SinglyLLLnode<T> *temp = NULL;
    
    if(pos < 0 || pos > this->iCount+1)
    {
        cout<<"Invalid position";
        return;
    }   

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        
        SinglyLLLnode<T> *newn = NULL;

        newn = new SinglyLLLnode<T>(no);

        int iCnt = 0;

        temp = this->first;

        for(iCnt =1;iCnt < pos-1;iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      DeleteAtPos
//  Input:              position
//  Output:             Nothing
//  Description:        Used to delete the node at given position position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLLnode<T> *temp = NULL;
    SinglyLLLnode<T> *target = NULL;

    int iCnt = 0;

    if(pos < 0 && pos > this->iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {

        int iCnt = 0;
        temp = this->first;
        for(iCnt=1;iCnt < pos-1;iCnt++)
        {
            temp = temp -> next;
        }

        target = temp -> next;
        temp -> next = temp -> next -> next;
        delete target;

        this->iCount--;
    }
}

//////////////////////////////////////////////////////////////////////
//      Doubly linerlinklist using Generic Approach
/////////////////////////////////////////////////////////////////////
#pragma pack(1)

template <class T>
class DoublyLLLnode 
{
    public:
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode *prev;
    
        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> * first;
        int iCount;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
    
};

template <class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Linklist gets created\n";

    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      InsertFirst
//  Input:              Data of node
//  Output:             Nothing
//  Description:        Used to add node at first position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      InsertLast
//  Input:              Data of node
//  Output:             Nothing
//  Description:        Used to add node at the last position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;
        
        while(temp -> next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      InsertAtPos
//  Input:              Data of node and position
//  Output:             Nothing
//  Description:        Used to add node at given position position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;

   if(pos < 1 || pos > this->iCount+1)
   {
        cout<<"Inavlis position\n";
        return;
   } 

   if(pos == 1)
   {
        this->InsertFirst(no);
   }
   else if(pos == this->iCount+1)
   {
     this->InsertLast(no);
   }
   else
   {
        newn = new DoublyLLLnode<T>(no);

        temp = this->first;
        for(iCnt =1; iCnt < pos -1; iCnt++)
        {
            temp= temp->next;
        }

        newn -> next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
   }

}


////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      DeleteFirst
//  Input:              Nothing
//  Output:             Nothing
//  Description:        Used to delete node the at first position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteFirst()
{

    if(this->first == NULL)                 
    {
        return;
    }   
    else if(this->first->next == NULL)      
    {
        delete this->first;
        this->first = NULL;
    }
    else                                   
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }

    this->iCount--;
}


////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      DeleteLast
//  Input:              Nothing
//  Output:             Nothing
//  Description:        Used to delete node the at Last position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if(this->first == NULL)                 
    {
        return;
    }   
    else if(this->first->next == NULL)      
    {
        delete this->first;
        this->first = NULL;
    }
    else                                    
    {
      temp = first;

      while(temp->next->next != NULL)
      {
        temp= temp->next;
      }

      delete temp->next;
      temp->next = NULL;
    }

    this->iCount--; 
}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      DeleteAtPos
//  Input:              position
//  Output:             Nothing
//  Description:        Used to delete the node at given position position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;

   if(pos < 1 || pos > this->iCount)
   {
        cout<<"Inavlis position\n";
        return;
   } 

   if(pos == 1)
   {
        this->DeleteFirst();
   }
   else if(pos == this->iCount)
   {
     this->DeleteLast();
   }
   else
   {
        temp = this->first;
        for(iCnt =1; iCnt < pos -1; iCnt++)
        {
            temp= temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev= temp;

        this->iCount--;
   }  
}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      Display
//  Input:              Nothing
//  Output:             Nothing
//  Description:        Used to display nodes in the linklist.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> *temp =NULL;

    temp =this->first;

    cout<<"\nNULL<=>";
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      Count
//  Input:              Nothing
//  Output:             Nothing
//  Description:        Used to count elements in the linklist.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
//      Singly circularlinklist using generic approach
//////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

template <class T>
class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode<T> *next;

        SinglyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T> * first;
        SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Inside constructor of SinglyCLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      InsertFirst
//  Input:              Data of node
//  Output:             Nothing
//  Description:        Used to add node at first position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(first == NULL && last == NULL)   
    {
        this->first = newn;
        this->last = newn;

        this->last->next = this->first;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;

        this->last->next = this->first;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      InsertLast
//  Input:              Data of node
//  Output:             Nothing
//  Description:        Used to add node at the last position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if((this->first == NULL) && (this->last == NULL))   
    {
        this->first = newn;
        this->last = newn;

        this->last->next = first;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;

        this->last->next = first;
    }

    this->iCount++;
}


////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      DeleteFirst
//  Input:              Nothing
//  Output:             Nothing
//  Description:        Used to delete the node at first position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first -> next;
        delete this->last->next;

        this->last->next = this->first;
    }

    this->iCount--;
}


////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      DeleteLast
//  Input:              Nothing
//  Output:             Nothing
//  Description:        Used to delete the node at Last position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        SinglyCLLnode<T> * temp = NULL;

        temp = this->first;

        while(temp -> next != this->last)
        {
            temp = temp -> next;
        }

        delete this->last;
        this->last = temp;

        this->last->next = this->first;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      Display
//  Input:              Nothing
//  Output:             Nothing
//  Description:        Used to display nodes in the linklist.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::Display()
{
    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }

    SinglyCLLnode<T> * temp = NULL;

    temp = this->first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    } while (temp != this->last ->next);
    
    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      Count
//  Input:              Nothing
//  Output:             Nothing
//  Description:        Used to count elements in the linklist.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCLL<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      DeleteAtPos
//  Input:              position
//  Output:             Nothing
//  Description:        Used to delete the node at given position position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * target = NULL;
    
    int iCnt = 0;
    
    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}


////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      InsertAtPos
//  Input:              Data of node and position
//  Output:             Nothing
//  Description:        Used to add node at given position position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next = newn;

        this->iCount++;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////
//      DoublyCircular LinklList  using generic approach
///////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

template <class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode<T> *next;
        DoublyCLLnode<T> *prev;

        DoublyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <class T>
class DoublyCLL
{
    private:
        DoublyCLLnode<T> * first;
        DoublyCLLnode<T> * last;
        int iCount;

    public:
        DoublyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

template <class T>
DoublyCLL<T>::DoublyCLL()
{
    cout<<"Inside constructor of DoublyCLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      InsertFirst
//  Input:              Data of node
//  Output:             Nothing
//  Description:        Used to add node at first position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode<T> * newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    if(first == NULL && last == NULL)   
    {
        this->first = newn;
        this->last = newn;

        this->first->prev =this->last;
        this->last->next = this->first;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;

        this->first = newn;

        this->first->prev = this->last;
        this->last->next = this->first;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      InsertLast
//  Input:              Data of node
//  Output:             Nothing
//  Description:        Used to add node at the last position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
    DoublyCLLnode<T> * newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    if((this->first == NULL) && (this->last == NULL))   
    {
        this->first = newn;
        this->last = newn;

        this->first->prev =this->last;
        this->last->next = this->first;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;

        this->last = newn;

        this->first->prev =this->last;
        this->last->next = this->first;

    }

    this->iCount++;
}


////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      DeleteFirst
//  Input:              Nothing
//  Output:             Nothing
//  Description:        Used to delete the node at first position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->first->prev;

        this->first->prev =this->last;
        this->last->next = this->first;
    }

    this->iCount--;
}


////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      DeleteLast
//  Input:              Nothing
//  Output:             Nothing
//  Description:        Used to delete the node at Last position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;
        delete this->last->next;

        this->first->prev =this->last;
        this->last->next = this->first;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      Display
//  Input:              Nothing
//  Output:             Nothing
//  Description:        Used to display nodes in the linklist.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::Display()
{
    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }

    DoublyCLLnode<T> * temp = NULL;

    temp = this->first;

    cout<<"\n<=>";
    do
    {
        cout<<"<=| "<<temp->data<<" | => ";
        temp = temp -> next;
    } while (temp != this->last ->next);
    cout<<"<=>\n";
}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      Count
//  Input:              Nothing
//  Output:             Nothing
//  Description:        Used to count elements in the linklist.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCLL<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      DeleteAtPos
//  Input:              position
//  Output:             Nothing
//  Description:        Used to delete the node at given position position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    DoublyCLLnode<T> * temp = NULL;
    
    int iCnt = 0;
    
    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}


////////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name:      InsertAtPos
//  Input:              Data of node and position
//  Output:             Nothing
//  Description:        Used to add node at given position position.
//  Author:             Atharva Sanjay Dhumal.
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::InsertAtPos(T no, int pos)
{
    DoublyCLLnode<T> * temp = NULL;
    DoublyCLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        newn->next->prev = newn;

        temp ->next = newn;
        newn ->prev = temp;

        this->iCount++;
    }
}

/////////////////////////////////////// END of Library/////////////////////////////////////////////////////
//      
////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    return 0;
}
