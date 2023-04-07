
/*
        AUTHOR: OM MANGESH WAGH
        DATE: 25/11/2022
        GOAL: TO CREATE EVENT DRIVEN CUSTOMISED VIRTUAL DATA STRUCTURE LIBRARY
*/

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyLinear
{
    public:
        PNODE First;

        SinglyLinear();

        void insertFirst (int element);
        void insertLast (int element);
        void insertAtPosition (int position, int element);

        void deleteFirst ();
        void deleteLast ();
        void deleteAtPosition (int position);

        void display ();
        int count();
};
class SinglyCircular
{
    public:
        PNODE First;
        PNODE Last;

        SinglyCircular();

        void insertFirst(int data);
        void insertLast(int data);
        void insertAtPosition(int position, int data);

        void deleteFirst();
        void deleteLast();
        void deleteAtPosition(int position);

        void display();
        int count();
};
class DoublyLinear
{
    public:
        PNODE First;

        DoublyLinear();

        void insertFirst(int data);
        void insertLast(int data);
        void insertAtPosition(int position, int data);

        void deleteFirst();
        void deleteLast();
        void deleteAtPosition(int position);

        void display();
        int count();
};
class DoublyCircular
{
    public:
        PNODE First;
        PNODE Last;

        DoublyCircular();

        void insertFirst(int data);
        void insertLast(int data); 
        void insertAtPosition(int position, int data); 

        void deleteFirst();
        void deleteLast(); 
        void deleteAtPosition(int position); 

        void display();
        int count(); 
};
class Stack
{
    public:
        struct node* First;
        int iCount;

        Stack();

        bool isStackEmpty();
        void push(int data);  // Insert
        int pop();            // Delete
        void display();
};
class Queue
{
    public:
        struct node* First;
        int iCount;

        Queue();

        bool isQueueEmpty();
        void enQueue(int data);  // Insert
        int deQueue();            // Delete
        void display();
};

int main (void)
{
    int choice = 0, element = 0, position = 0, element_count = 0;
    int type_data_structure = 0, type_linked_list = 0;

    cout<<"\n"<<"------------------WELCOME TO CUSTOMISED DATA STRUCTURE LIBRARY--------------------"<<"\n";

    while(1)
    {  
        cout<<"\n"<<"Which Data Structure Would You Like To Create"<<"\n"
                <<"\n"<<"Press 1 : Linked List"<<"\n"
                "Press 2 : Stack"<<"\n"
                "Press 3 : Queue"<<"\n"
                "Press 4 : Exit Application"<<"\n";
        
        cin>>type_data_structure;

        if(type_data_structure == 1)
        {
            while(1)
            {
                cout<<"\n"<<"---------WELCOME TO LINKED LIST---------"<<"\n";

                cout<<"\n"<<"Which Linked List Would You Like To Create"<<"\n"
                        <<"\n"<<"Press 1 : Singly Linear Linked List"<<"\n"
                        "Press 2 : Singly Circular Linked List"<<"\n"
                        "Press 3 : Doubly Linear Linked List"<<"\n"
                        "Press 4 : Doubly Circular Linked List"<<"\n"
                        "Press 5 : Exit Linked List"<<"\n";
                
                cin>>type_linked_list;

                if(type_linked_list == 1)
                {
                    SinglyLinear linkedlist;
                    cout<<"\n"<<"---------WELCOME TO SINGLY LINEAR LINKED LIST---------"<<"\n\n";

                    while (1)
                    {
                        cout<<"-----------------------------------------------------------"<<"\n";

                        cout<<"Press 1: Insert element at First position"<<"\n";
                        cout<<"Press 2: Insert element at last position"<<"\n";
                        cout<<"Press 3: Insert element at given position"<<"\n";
                        cout<<"Press 4: Delete element at First position"<<"\n";
                        cout<<"Press 5: Delete element at last position"<<"\n";
                        cout<<"Press 6: Delete element at given position"<<"\n";
                        cout<<"Press 7: Display elements of Linked List"<<"\n";
                        cout<<"Press 8: Count elements of Linked List"<<"\n";
                        cout<<"Press 9: Exit Singly Linear Linked List"<<"\n";

                        cin>>choice;

                        if(choice == 1)
                        {
                            cout<<"Enter element :"<<"\n";
                            cin>>element;
                            linkedlist.insertFirst (element);
                        }
                        else if(choice == 2)
                        {
                            cout<<"Enter element :"<<"\n";
                            cin>>element;
                            linkedlist.insertLast (element);
                        }
                        else if(choice == 3)
                        {
                            cout<<"Enter element :"<<"\n";
                            cin>>element;
                            cout<<"Enter position of element :"<<"\n";
                            cin>>position;
                            linkedlist.insertAtPosition (element,position);
                        }
                        else if(choice == 4)
                        {
                            linkedlist.deleteFirst ();
                        }
                        else if(choice == 5)
                        {
                            linkedlist.deleteLast ();
                        }
                        else if(choice == 6)
                        {
                            cout<<"Enter position of element to delete:"<<"\n";
                            cin>>position;
                            linkedlist.deleteAtPosition(position);
                        }
                        else if(choice == 7)
                        {
                            linkedlist.display();
                        }
                        else if(choice == 8)
                        {
                            element_count = linkedlist.count();
                            cout<<"Number of nodes in Singly Linear Linked List are: "<<element_count<<"\n";
                        }
                        else if(choice == 9)
                        {
                            cout<<"Thank You For Using Singly Linear Linked List :)"<<"\n";
                            break;
                        }
                        else
                        {
                            cout<<"Invalid choice"<<"\n";
                        }
                    }
                }
                else if(type_linked_list == 2)
                {
                    SinglyCircular linkedlist;
                    cout<<"\n"<<"---------WELCOME TO SINGLY CIRCULAR LINKED LIST---------"<<"\n\n";

                    while (1)
                    {
                        cout<<"-----------------------------------------------------------"<<"\n";

                        cout<<"Press 1: Insert element at First position"<<"\n";
                        cout<<"Press 2: Insert element at last position"<<"\n";
                        cout<<"Press 3: Insert element at given position"<<"\n";
                        cout<<"Press 4: Delete element at First position"<<"\n";
                        cout<<"Press 5: Delete element at last position"<<"\n";
                        cout<<"Press 6: Delete element at given position"<<"\n";
                        cout<<"Press 7: Display elements of Linked List"<<"\n";
                        cout<<"Press 8: Count elements of Linked List"<<"\n";
                        cout<<"Press 9: Exit Singly Circular Linked List"<<"\n";

                        cin>>choice;

                        if(choice == 1)
                        {
                            cout<<"Enter element :"<<"\n";
                            cin>>element;
                            linkedlist.insertFirst (element);
                        }
                        else if(choice == 2)
                        {
                            cout<<"Enter element :"<<"\n";
                            cin>>element;
                            linkedlist.insertLast (element);
                        }
                        else if(choice == 3)
                        {
                            cout<<"Enter element :"<<"\n";
                            cin>>element;
                            cout<<"Enter position of element :"<<"\n";
                            cin>>position;
                            linkedlist.insertAtPosition (element,position);
                        }
                        else if(choice == 4)
                        {
                            linkedlist.deleteFirst ();
                        }
                        else if(choice == 5)
                        {
                            linkedlist.deleteLast ();
                        }
                        else if(choice == 6)
                        {
                            cout<<"Enter position of element to delete:"<<"\n";
                            cin>>position;
                            linkedlist.deleteAtPosition(position);
                        }
                        else if(choice == 7)
                        {
                            linkedlist.display();
                        }
                        else if(choice == 8)
                        {
                            element_count = linkedlist.count();
                            cout<<"Number of nodes in Singly Circular Linked List are: "<<element_count<<"\n";
                        }
                        else if(choice == 9)
                        {
                            cout<<"Thank You For Using Singly Circular Linked List :)"<<"\n";
                            break;
                        }
                        else
                        {
                            cout<<"Invalid choice"<<"\n";
                        }
                    }   
                }
                else if(type_linked_list == 3)
                {
                    DoublyLinear linkedlist;
                    cout<<"\n"<<"---------WELCOME TO DOUBLY LINEAR LINKED LIST---------"<<"\n\n";

                    while (1)
                    {
                        cout<<"-----------------------------------------------------------"<<"\n";

                        cout<<"Press 1: Insert element at First position"<<"\n";
                        cout<<"Press 2: Insert element at last position"<<"\n";
                        cout<<"Press 3: Insert element at given position"<<"\n";
                        cout<<"Press 4: Delete element at First position"<<"\n";
                        cout<<"Press 5: Delete element at last position"<<"\n";
                        cout<<"Press 6: Delete element at given position"<<"\n";
                        cout<<"Press 7: Display elements of Linked List"<<"\n";
                        cout<<"Press 8: Count elements of Linked List"<<"\n";
                        cout<<"Press 9: Exit Doubly Linear Linked List"<<"\n";

                        cin>>choice;

                        if(choice == 1)
                        {
                            cout<<"Enter element :"<<"\n";
                            cin>>element;
                            linkedlist.insertFirst (element);
                        }
                        else if(choice == 2)
                        {
                            cout<<"Enter element :"<<"\n";
                            cin>>element;
                            linkedlist.insertLast (element);
                        }
                        else if(choice == 3)
                        {
                            cout<<"Enter element :"<<"\n";
                            cin>>element;
                            cout<<"Enter position of element :"<<"\n";
                            cin>>position;
                            linkedlist.insertAtPosition (position,element);
                        }
                        else if(choice == 4)
                        {
                            linkedlist.deleteFirst ();
                        }
                        else if(choice == 5)
                        {
                            linkedlist.deleteLast ();
                        }
                        else if(choice == 6)
                        {
                            cout<<"Enter position of element to delete:"<<"\n";
                            cin>>position;
                            linkedlist.deleteAtPosition(position);
                        }
                        else if(choice == 7)
                        {
                            linkedlist.display();
                        }
                        else if(choice == 8)
                        {
                            element_count = linkedlist.count();
                            cout<<"Number of nodes in Doubly Linear Linked List are: "<<element_count<<"\n";
                        }
                        else if(choice == 9)
                        {
                            cout<<"Thank You For Using Doubly Linear Linked List :)"<<"\n";
                            break;
                        }
                        else
                        {
                            cout<<"Invalid choice"<<"\n";
                        }
                    }   
                }
                else if(type_linked_list == 4)
                {
                    DoublyCircular linkedlist;
                    cout<<"\n"<<"---------WELCOME TO DOUBLY CIRCULAR LINEAR LINKED LIST---------"<<"\n\n";

                    while (1)
                    {
                        cout<<"-----------------------------------------------------------"<<"\n";

                        cout<<"Press 1: Insert element at First position"<<"\n";
                        cout<<"Press 2: Insert element at last position"<<"\n";
                        cout<<"Press 3: Insert element at given position"<<"\n";
                        cout<<"Press 4: Delete element at First position"<<"\n";
                        cout<<"Press 5: Delete element at last position"<<"\n";
                        cout<<"Press 6: Delete element at given position"<<"\n";
                        cout<<"Press 7: Display elements of Linked List"<<"\n";
                        cout<<"Press 8: Count elements of Linked List"<<"\n";
                        cout<<"Press 9: Exit Doubly Circular Linked List"<<"\n";

                        cin>>choice;

                        if(choice == 1)
                        {
                            cout<<"Enter element :"<<"\n";
                            cin>>element;
                            linkedlist.insertFirst (element);
                        }
                        else if(choice == 2)
                        {
                            cout<<"Enter element :"<<"\n";
                            cin>>element;
                            linkedlist.insertLast (element);
                        }
                        else if(choice == 3)
                        {
                            cout<<"Enter element :"<<"\n";
                            cin>>element;
                            cout<<"Enter position of element :"<<"\n";
                            cin>>position;
                            linkedlist.insertAtPosition (position,element);
                        }
                        else if(choice == 4)
                        {
                            linkedlist.deleteFirst ();
                        }
                        else if(choice == 5)
                        {
                            linkedlist.deleteLast ();
                        }
                        else if(choice == 6)
                        {
                            cout<<"Enter position of element to delete:"<<"\n";
                            cin>>position;
                            linkedlist.deleteAtPosition(position);
                        }
                        else if(choice == 7)
                        {
                            linkedlist.display();
                        }
                        else if(choice == 8)
                        {
                            element_count = linkedlist.count();
                            cout<<"Number of nodes in Doubly Circular Linked List are: "<<element_count<<"\n";
                        }
                        else if(choice == 9)
                        {
                            cout<<"Thank You For Using Doubly Circular Linked List :)"<<"\n";
                            break;
                        }
                        else
                        {
                            cout<<"Invalid choice"<<"\n";
                        }
                    }   
                }
                else if(type_linked_list == 5)
                {
                    cout<<"Thank You For Using Linked List :)"<<"\n";
                    break;
                }
                else
                {   
                    cout<<"Invalid Choice"<<"\n";
                }
            }
        }
        else if(type_data_structure == 2)
        {
            Stack stack;
            cout<<"\n"<<"---------WELCOME TO STACK---------"<<"\n\n";

            while (1)
            {
                cout<<"-----------------------------------------------------------"<<"\n";

                cout<<"Press 1: Check if Stack is empty"<<"\n";
                cout<<"Press 2: Push element"<<"\n";
                cout<<"Press 3: Pop element"<<"\n";
                cout<<"Press 4: Display elements of Stack"<<"\n";
                cout<<"Press 5: Exit Stack"<<"\n";

                cin>>choice;

                if(choice == 1)
                {
                    bool flag = false;
                    (stack.isStackEmpty() ? cout<<"Stack is empty"<<"\n" : cout<<"Stack is not empty"<<"\n");
                }
                else if(choice == 2)
                {
                    cout<<"Enter element :"<<"\n";
                    cin>>element;
                    stack.push(element);
                }
                else if(choice == 3)
                {
                    stack.pop();
                }
                else if(choice == 4)
                {
                    stack.display();
                }
                else if(choice == 5)
                {
                    cout<<"Thank You For Using Stack :)"<<"\n";
                    break;
                }
                else
                {
                    cout<<"Invalid choice"<<"\n";
                }
            }
        }
        else if(type_data_structure == 3)
        {
            Queue queue;
            cout<<"\n"<<"---------WELCOME TO Queue---------"<<"\n\n";

            while (1)
            {
                cout<<"-----------------------------------------------------------"<<"\n";

                cout<<"Press 1: Check if Queue is empty"<<"\n";
                cout<<"Press 2: EnQueue element"<<"\n";
                cout<<"Press 3: DeQueue element"<<"\n";
                cout<<"Press 4: Display elements of Queue"<<"\n";
                cout<<"Press 5: Exit Queue"<<"\n";

                cin>>choice;

                if(choice == 1)
                {
                    bool flag = false;
                    (queue.isQueueEmpty() ? cout<<"Queue is empty"<<"\n" : cout<<"Queue is not empty"<<"\n");
                }
                else if(choice == 2)
                {
                    cout<<"Enter element :"<<"\n";
                    cin>>element;
                    queue.enQueue(element);
                }
                else if(choice == 3)
                {
                    queue.deQueue();
                }
                else if(choice == 4)
                {
                    queue.display();
                }
                else if(choice == 5)
                {
                    cout<<"Thank You For Using Queue :)"<<"\n";
                    break;
                }
                else
                {
                    cout<<"Invalid choice"<<"\n";
                }
            }
        }
        else if(type_data_structure == 4)
        {
            cout<<"Thank You For Using This Application!! :)"<<"\n";
            return (0);
        }
        else
        {
            cout<<"Invalid Choice"<<"\n";
        }
    }

    return (0);
}

SinglyLinear :: SinglyLinear()
{
    First = NULL;
}

void SinglyLinear :: display()
{
    cout<<"Elements of Singly Linear Linked List are: "<<"\n";
    PNODE temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

void SinglyLinear :: insertFirst(int element)
{
    PNODE newn = new NODE;

    newn->data = element;
    newn->next = NULL;

    if(First == NULL)
        First = newn;
    else
    {
        newn->next = First;
        First = newn;
    }
}

void SinglyLinear :: insertLast(int element)
{
    PNODE newn = new NODE;
    PNODE temp = NULL;

    newn->data = element;
    newn->next = NULL;

    if(First == NULL)
        First = newn;
    else
    {
        temp = First;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newn;
    }
}

void SinglyLinear :: insertAtPosition(int position, int element)
{
    int node_count = count(), iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    if((position < 1) || (position > node_count+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(position == 1)
        insertFirst(element);
    else if(position == node_count+1)
        insertLast(element);
    else 
    {
        newn = new NODE;

        newn->data = element;
        newn->next = NULL;

        temp = First;
        for(iCnt = 1; iCnt < (position-1); ++iCnt)
            temp = temp->next;
        
        newn->next = temp->next;
        temp->next = newn;

    }
}

void SinglyLinear :: deleteFirst()
{
    PNODE temp = NULL;

    if(First == NULL)
        return;
    else if((First)->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

void SinglyLinear :: deleteLast()
{
    PNODE temp = NULL;

    if(First == NULL)
        return;
    else if((First)->next == NULL)
    {
        free (First);
        First = NULL;
    }
    else
    {
        temp = First;
        while(temp->next->next != NULL)
            temp = temp->next;
        free (temp->next);
        temp->next = NULL;
    }
}

void SinglyLinear :: deleteAtPosition(int position)
{
    int node_count = count(), iCnt = 0;
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    if((position < 1) || (position > node_count))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(position == 1)
        deleteFirst();
    else if(position == node_count)
        deleteLast();
    else 
    {
        temp1 = First;
        for(iCnt = 1; iCnt < (position-1); ++iCnt)
            temp1 = temp1->next;
        
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
}

int SinglyLinear :: count()
{
    PNODE temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        temp = temp->next;
        iCnt++;
    }
    return iCnt;

}

SinglyCircular :: SinglyCircular()
{
    First = NULL;
    Last = NULL;
}

void SinglyCircular :: insertFirst(int data)
{
    PNODE newn = new NODE;

    newn->data = data;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    (Last)->next = First;
}

void SinglyCircular :: insertLast(int data)
{
    PNODE newn = new NODE;

    newn->data = data;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        (Last)->next = newn;
        Last = newn;
    }
    (Last)->next = First;
}

void SinglyCircular :: insertAtPosition(int position, int data)
{
    int nodeCnt = count();
    int iCnt = 0;
    PNODE temp = NULL;

    PNODE newn = NULL;

    if((position < 1) || (position > nodeCnt+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(position == 1)
    {
        insertFirst(data);
    }
    else if(position == nodeCnt+1)
    {
        insertLast(data);
    }
    else
    {
        newn = new NODE;

        newn->data = data;
        newn->next = NULL;

        temp = First;
        for(iCnt = 1; iCnt < position-1; ++iCnt)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void SinglyCircular :: deleteFirst()
{
    PNODE temp = NULL;

    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(((First)->next == NULL))
    {
        delete (First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        temp = First;
        First = (First)->next;
        delete (temp);
        (Last)->next = First;
    }
}

void SinglyCircular :: deleteLast()
{
    PNODE temp = NULL;
    int iCnt = 0;

    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(((First)->next == NULL))
    {
        delete (First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        temp = First;

        while(temp->next != Last)
        {
            temp = temp->next;
        }

        Last = temp;
        delete (temp->next);
        (Last)->next = First;
    }
}

void SinglyCircular :: deleteAtPosition(int position)
{
    int nodeCnt = count();
    int iCnt = 0;
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    if((position < 1) || (position > nodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(position == 1)
    {
        deleteFirst();
    }
    else if(position == nodeCnt)
    {
        deleteLast();
    }
    else
    {
        temp1 = First;
        for(iCnt = 1; iCnt < position-1; ++iCnt)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete (temp2);
    }
}

void SinglyCircular :: display()
{
    PNODE temp = First;

    cout<<"Elements of Singly Circular Linked List are:"<<"\n";
    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    while(temp != Last->next);
    cout<<"NULL\n"<<"\n";
}

int SinglyCircular :: count()
{
    PNODE temp = First;
    int count = 0;
    do
    {
        count++;
        temp = temp->next;
    }
    while(temp != Last->next);
    return (count);
}

DoublyLinear :: DoublyLinear()
{
    First = NULL;
}

void DoublyLinear :: insertFirst(int data)
{
    PNODE newn = new NODE;

    newn->data = data;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        (First)->prev = newn;
        First = newn;
    }
}

void DoublyLinear :: insertLast(int data)
{
    PNODE newn = new NODE;
    PNODE temp = NULL;

    newn->data = data;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
}

void DoublyLinear :: insertAtPosition(int position, int data)
{
    int nodeCnt = count();
    int iCnt = 0;
    PNODE newn = new NODE;
    PNODE temp = NULL;

    newn->data = data;
    newn->next = NULL;
    newn->prev = NULL;

    if((position < 1) || (position > nodeCnt+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(position == 1)
    {
        insertFirst(data);
    }
    else if(position == nodeCnt+1)
    {
        insertLast(data);
    }
    else
    {
        temp = First;
        for(iCnt = 1; iCnt < position-1; ++iCnt)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
}

void DoublyLinear :: deleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if((First)->next == NULL)
    {
        free(First);
        First = NULL;
    }
    else
    {
        First = (First)->next;
        free((First)->prev); 
        (First)->prev = NULL;
    }
}

void DoublyLinear :: deleteLast()
{
    PNODE temp = First;

    if(First == NULL)
    {
        return;
    }
    else if((First)->next == NULL)
    {
        free(First);
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        
        free(temp->next); 
        temp->next = NULL;
    }
}

void DoublyLinear :: deleteAtPosition(int position)
{
    int nodeCnt = count();
    int iCnt = 0;
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    if((position < 1) || (position > nodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(position == 1)
    {
        deleteFirst();
    }
    else if(position == nodeCnt)
    {
        deleteLast();
    }
    else
    {
        temp1 = First;
        for(iCnt = 1; iCnt < position-1; ++iCnt)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->prev = temp1;
        free(temp2);
    }
}

void DoublyLinear :: display()
{
    PNODE temp = First;
    cout<<"Elements of Doubly Linear Linked List : "<<"\n";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

int DoublyLinear :: count()
{
    PNODE temp = First;
    int count = 0;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return (count);
}

DoublyCircular :: DoublyCircular()
{
    First = NULL;
    Last = NULL;
}

void DoublyCircular :: insertFirst(int data)
{
    PNODE newn = new NODE;

    newn->data = data;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        (First)->prev = newn;
        First = newn;
    }
    (Last)->next = First;
    (First)->prev = Last;
}

void DoublyCircular :: insertLast(int data)
{
    PNODE newn = new NODE;

    newn->data = data;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->prev = Last;
        (Last)->next = newn;
        Last = newn;
    }
    (Last)->next = First;
    (First)->prev = Last;
}

void DoublyCircular :: insertAtPosition(int position, int data)
{
    int nodeCnt = count();
    int iCnt = 0;
    PNODE newn = new NODE;
    PNODE temp = NULL;

    newn->data = data;
    newn->next = NULL;
    newn->prev = NULL;

    if((position < 1) || (position > nodeCnt+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(position == 1)
    {
        insertFirst(data);
    }
    else if(position == nodeCnt+1)
    {
        insertLast(data);
    }
    else
    {
        temp = First;
        for(iCnt = 1; iCnt < position-1; ++iCnt)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
    }
}

void DoublyCircular :: deleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if((First)->next == NULL)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = (First)->next;
        delete (First)->prev;
        (Last)->next = First;
        (First)->prev = Last;
    }
}

void DoublyCircular :: deleteLast()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = (Last)->prev;
        delete (Last)->next;
        (Last)->next = First;
        (First)->prev = Last;
    }
}

void DoublyCircular :: deleteAtPosition(int position)
{
    int nodeCnt = count();
    int iCnt = 0;
    PNODE temp = NULL;

    if((position < 1) || (position > nodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(position == 1)
    {
        deleteFirst();
    }
    else if(position == nodeCnt)
    {
        deleteLast();
    }
    else
    {
        temp = First;
        for(iCnt = 1; iCnt < position-1; ++iCnt)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete (temp->next->prev);
        temp->next->prev = temp;
    }
}

void DoublyCircular :: display()
{
    PNODE temp = First;
    cout<<"Elements of Doubly Circular Linked List are : "<<"\n";
    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    while(temp != Last->next);
    cout<<"NULL"<<"\n";
}

int DoublyCircular :: count()
{
    PNODE temp = First;
    int count = 0;
    do
    {
        count++;
        temp = temp->next;
    }
    while(temp != Last->next);

    return (count);
}

Stack :: Stack()
{
    First = NULL;
    iCount = 0;
}

bool Stack :: isStackEmpty()
{
    if(iCount == 0)
        return true;
    else
        return false;
}

void Stack :: push(int data)  // InsertFirst
{
    struct node* newn = new node;

    newn->data = data;
    newn->next = NULL;

    if(First == NULL)
        First= newn;
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

int Stack :: pop()            // DeleteFirst
{
    if(First == NULL)
    {
        cout<<"unable to pop element as stack is empty"<<"\n";
        return (-1);
    }
    else
    {
        int value = First->data;
        struct node* temp = First;

        First = First->next;
        delete temp;

        iCount--;
        return value;
    }
}

void Stack :: display()
{
    if(First == NULL)
        cout<<"Stack is empty"<<"\n";
    else
    {
        cout<<"Elements of Stack are : "<<"\n";

        struct node* temp = First;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |-> ";
            temp = temp->next;
        }
        cout<<"NULL"<<"\n";
    }
}

Queue :: Queue()
{
    First = NULL;
    iCount = 0;
}

bool Queue :: isQueueEmpty()
{
    if(iCount == 0)
        return true;
    else
        return false;
}

void Queue :: enQueue(int data)  // InsertLast
{
    struct node* newn = new node;

    newn->data = data;
    newn->next = NULL;

    if(First == NULL)
        First= newn;
    else
    {
        struct node* temp = First;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newn;
    }
    iCount++;
}

int Queue :: deQueue()            // DeleteFirst
{
    if(First == NULL)
    {
        cout<<"Unable to dequeue element as queue is empty"<<"\n";
        return (-1);
    }
    else
    {
        int value = First->data;
        struct node* temp = First;

        First = First->next;
        delete temp;

        iCount--;
        return value;
    }
}

void Queue :: display()
{
    if(First == NULL)
        cout<<"Queue is empty"<<"\n";
    else
    {
        cout<<"Elements of Queue are : "<<"\n";

        struct node* temp = First;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |-> ";
            temp = temp->next;
        }
        cout<<"NULL"<<"\n";
    }
}
