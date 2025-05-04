// C++ program to perform operations such as insertion, deletion, search, display and reverse on linked list
#include <iostream>
using namespace std;

class list
{
private:
    struct node
    {
        int data;
        struct node *next;
    } *head;
    typedef struct node node;

public:
    list();
    node *GetHead();
    void Display();
    void InsertBeg(int);
    void InsertEnd(int);
    bool InsertPos(int, int);
    int DeleteBeg();
    int DeleteEnd();
    int DeletePos(int);
    int Search(int);
    void DisplayRev(node *);
    void Reverse();
};

int main()
{
    int choice, stop = 0;
    int pos, num;
    list linkedlist;
    while (!stop)
    {
        cout << "\n\nMENU :";
        cout << "\n 1. Insertion in Beginning\n 2. Insertion in End\n 3. Insertion at Position";
        cout << "\n 4. Deletion in Beginning\n 5. Deletion in End\n 6. Deletion at Position";
        cout << "\n 7. Search in List \n 8. Display List\n 9. Display in Reverse\n 10. Reverse the List\n 11. Exit" << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert : ";
            cin >> num;
            linkedlist.InsertBeg(num);
            cout << "Insertion Succesful." << endl;
            break;

        case 2:
            cout << "Enter value to insert : ";
            cin >> num;
            linkedlist.InsertEnd(num);
            cout << "Insertion Succesful." << endl;
            break;

        case 3:
            cout << "Enter value to insert : ";
            cin >> num;
            cout << "Enter position to insert : ";
            cin >> pos;
            if (linkedlist.InsertPos(num, pos))
            {
                cout << "Insertion Succesful." << endl;
            }
            else
            {
                cout << "Invalid Position. Insertion Failed." << endl;
            }
            break;

        case 4:
            num = linkedlist.DeleteBeg();
            if (num != -1)
            {
                cout << "Deletion Succesful. Deleted value : " << num;
            }
            else
            {
                cout << "Deletion failed." << endl;
            }
            break;

        case 5:
            num = linkedlist.DeleteEnd();
            if (num != -1)
            {
                cout << "Deletion Succesful. Deleted value : " << num;
            }
            else
            {
                cout << "Deletion failed." << endl;
            }
            break;

        case 6:
            cout << "Enter position to delete : ";
            cin >> pos;
            num = linkedlist.DeletePos(pos);
            if (num != -1)
            {
                cout << "Deletion Succesful. Deleted value : " << num;
            }
            else
            {
                cout << "Deletion failed." << endl;
            }
            break;

        case 7:
            cout << "\nEnter element to search for : ";
            cin >> num;
            pos = linkedlist.Search(num);
            if (pos == -1)
            {
                cout << "Search failed." << endl;
            }
            else
            {
                cout << "Search successful.\nElement found at index : " << pos;
            }
            break;

        case 8:
            linkedlist.Display();
            break;

        case 9:
            linkedlist.DisplayRev(linkedlist.GetHead());
            break;

        case 10:
        linkedlist.Reverse();
            cout << "Reversal Successful." << endl;
            break;

        case 11:
            stop = 1;
            cout << "Exitting code." << endl;
            break;

        default:
            cout << "Invalid choice. Enter again." << endl;
            break;
        }
    }
}

// Constructor function to initialize head to NULL
list::list()
{
    head = NULL;
}

// Getter function to access the head
list::node *list::GetHead()
{
    return head;
}

// Function to display the linked list

void list::Display()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << "NULL";
}

// Function to display the linked list in reverse

void list::DisplayRev(node *head)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    if (head->next == nullptr)
    {
        cout << "NULL";
    }
    if (head->next != nullptr)
    {
        DisplayRev(head->next);
    }
    cout << " <-- " << head->data;
}

// Function to insert an element in the beginning of the linked list

void list::InsertBeg(int num)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = num;
    newnode->next = head;
    head = newnode;
}

// Function to insert an element in the end of the linked list

void list::InsertEnd(int num)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = num;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Function to insert an element at the user-specified position in the linked list

bool list::InsertPos(int num, int pos)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = num;
    if (pos < 0)
    {
        return 0;
    }
    else if (pos == 0)
    {
        newnode->next = head;
        head = newnode;
        return 1;
    }
    else
    {
        node *temp = head;
        for (int i = 1; i < pos && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            return 0;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        return 1;
    }
}

// Function to delete the first element of the linked list

int list::DeleteBeg()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return -1;
    }
    else
    {
        int value = head->data;
        node *temp = head;
        head = head->next;
        free(temp);
        return value;
    }
}

// Function to delete the last element of the linked list

int list::DeleteEnd()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return -1;
    }
    else
    {
        node *temp = head;
        if (temp->next == NULL)
        {
            int value = temp->data;
            free(head);
            head = NULL;
            return value;
        }
        else
        {
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            int value = temp->next->data;
            temp->next = temp->next->next;
            free(temp->next);
            return value;
        }
    }
}

// Function to delete the element at the user-specified position in the linked list

int list::DeletePos(int pos)
{
    if (head == NULL || pos < 0)
    {
        cout << "List is empty." << endl;
        return -1;
    }
    node *temp = head;
    if (pos == 0)
    {
        int value = head->data;
        head = head->next;
        free(temp);
        return value;
    }
    else
    {
        int i = 1;
        while (temp->next != NULL && i < pos)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next == NULL)
        {
            cout << "Invalid Position." << endl;
            return -1;
        }
        node *del = temp->next;
        int value = del->data;
        temp->next = del->next;
        free(del);
        return value;
    }
}

// Function to search for an element in the linked list

int list::Search(int num)
{
    node *temp = head;
    int index = 0;
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

// Function to reverse the linked list

void list::Reverse()
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    node *temp = head;
    head = NULL;
    while (temp != NULL)
    {
        node *var = temp->next;
        temp->next = head;
        head = temp;
        temp = var;
    }
}