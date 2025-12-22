 //OOP
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class SinglyLL
{
    public:
        PNODE first;
        int iCount;

        SinglyLL()
        {
            cout<<"Object of singlyLL gets created.\n";
            first = NULL;
            iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;

            temp = first;

            if(first == NULL)
            {
                first = newn;
                iCount++;
            }
            else
            {
                newn -> next = first;
                first = newn;
                iCount++;
            }

        }

        void InsertLast(int no)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;

            if(first == NULL)
            {
                first = newn;
                iCount++;
            }
            else
            {
                temp = first;

                while(temp -> next != NULL)
                {
                    temp = temp -> next;
                }

                temp -> next = newn;
                iCount++;
            }

        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if(first == NULL)
            {
                return;
            }
            else if(first -> next == NULL)
            {
                free(first);
                first = NULL;
                iCount--;
            }
            else
            {
                temp = first;

                first = temp -> next;
                free(temp);
                iCount--;
            }
        }

        void DeleteLast()
        {
            PNODE temp = NULL;
            if(first == NULL)
            {
                return;
            }
            else if(first -> next == NULL)
            {
                free(first);
                first = NULL;
                iCount--;
            }
            else
            {
                temp = first;
                
                while(temp->next->next != NULL)
                {
                   temp = temp -> next;
                }

                free(temp->next);
                temp->next = NULL;
                iCount--;
            }
        }

        void Display()
        {
            PNODE temp = NULL;

            temp = first;

            while( temp != NULL)
            {
                printf("|%d|->",temp -> data);
                temp = temp->next;
            }
            printf("NULL\n");
        }

        int Count()
        {
            return iCount;
        }

        void InsertAtPos(int no,int pos)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;
            int i = 0;

            if(pos < 0 && pos > iCount+1)
            {
                printf("Invalid Position");
                return;
            }

            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if(pos == iCount+1)
            {
                InsertLast(no);
            }
            else
            {
                 newn = new NODE;
                newn -> data = no;
                newn -> next = NULL;

                temp = first;
                for(i=1; i < pos-1;i++)
                {
                    temp = temp -> next;
                }

                newn -> next = temp -> next;
                temp -> next = newn;
                iCount++;
            }

        }

        void DeleteAtPos(int pos)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;
            PNODE target = NULL;

            int i = 0;

            if(pos < 0 && pos > iCount+1)
            {
                printf("Invalid Position");
                return;
            }

            if(pos == 1)
            {
                DeleteFirst();
            }
            else if(pos == iCount)
            {
                DeleteLast();
            }
            else
            {
                PNODE temp = NULL;

                int i = 0;
                temp = first;
                for(i=1;i < pos-1;i++)
                {
                    temp = temp -> next;
                }

                target = temp -> next;
                temp -> next = temp -> next -> next;
                free(target);
                iCount--;
            }
        }
        

};

int main()
{
    SinglyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of nodes are :"<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of nodes are :"<<iRet<<"\n";

    obj.DeleteFirst();

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of nodes are :"<<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of nodes are :"<<iRet<<"\n";

    obj.InsertAtPos(110,4);

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of nodes are :"<<iRet<<"\n";

    obj.DeleteAtPos(4);

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of nodes are :"<<iRet<<"\n";



    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////
//
//Object of singlyLL gets created.
////|11|->|21|->|51|->NULL
//Number of nodes are :3
//|11|->|21|->|51|->|101|->|111|->|121|->NULL
//Number of nodes are :6
//|21|->|51|->|101|->|111|->|121|->NULL
//Number of nodes are :5
//|21|->|51|->|101|->|111|->NULL
//Number of nodes are :4
//|21|->|51|->|101|->|110|->|111|->NULL
//Number of nodes are :5
//|21|->|51|->|101|->|111|->NULL
//Number of nodes are :4
//
/////////////////////////////////////////////////////////////////////////////////////////////
