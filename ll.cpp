#include <iostream>
using namespace std;

template <class T>
class LList
{
    struct Node
    {
        T data;
        Node *next;
    };
    Node *head;

public:
    LList()
    {
        head = NULL;
    }

    void Insertion(T Value, int Loc)
    {
        Node *temp = new Node();
        temp->data = Value;
        temp->next = NULL;
        if(count()==0){
            head= temp;
         

        }
        else{


        if (Loc == -1)
        {
            
        
            Node *temp1 = new Node();
            temp1 =  head;
            
            while(temp1->next!= NULL)
            {
                temp1 = temp1->next;
            }
            temp1->next = temp;
            
           // cout << "Invalid" << endl;
        }
        else if (Loc == 1)
        {
            temp->next = head;
            head= temp;
        }
        else if (Loc <= count())
        {
            Node *temp1 = head;
            for (int i = 1; i < Loc -1; i++)
            {
                if (temp1 != NULL)
                {
                    temp1 = temp1->next;
                }
            }
            if (temp1 != NULL)
            {
                temp->next = temp1->next;
                temp1->next = temp;
            }
            else
            {
                cout << "Invalid" << endl;
            }
        }
        else{
             cout << "Invalid position" << endl;
        }
        }
    }
    void DeleteItemAt(int Pos)
    {
        if (Pos <= 0 || head == NULL)
        {
            cout << "Invalid position or empty list" << endl;
            return;
        }

        if (Pos == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i < Pos - 1; i++)
            {
                if (temp != NULL)
                {
                    temp = temp->next;
                }
                else
                {
                    cout << "Invalid position" << endl;
                    return;
                }
            }

            if (temp != NULL && temp->next != NULL)
            {
                Node *temp2 = temp->next;
                temp->next = temp2->next;
                delete temp2;
            }
            else
            {
                cout << "Invalid position" << endl;
            }
        }
    }
    int count()
             {
                  Node *current;
                  int c=0;
                  current=head;
                  while(current!=NULL)
                  {
                                      c++;
                                      current=current->next;
                  }
                  return c;
             }


    int Searching(T Value)
    {
        Node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            if (temp->data == Value)
            {
                return count;
            }
            temp = temp->next;
        }
        return -1; // Item not found
    }

    void display()
    {
        Node *temp = head;
        cout << "List of elements are: ";
        if (temp != NULL)
        {
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "List is empty" << endl;
        }
    }
};

int main()
{
    LList<char> L1;
    int choice, pos;
    char value;

    do
    {
        cout << "\n1. Insert an item\n2. Delete an item\n3. Display linked list\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            cout << "Enter the position to insert at:(insert -1 if you want to insert at end of list ";
            cin >> pos;
            L1.Insertion(value, pos);
            break;

        case 2:
            cout << "Enter the position to delete: ";
            cin >> pos;
            L1.DeleteItemAt(pos);
            break;

        case 3:
            L1.display();
            break;

        case 0:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
