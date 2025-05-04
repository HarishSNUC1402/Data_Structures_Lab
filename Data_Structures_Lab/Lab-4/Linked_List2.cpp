// C++ program to perform operations such as insertion in ascending order, merging and display on linked lists
#include <iostream>
#include "Linked_List2.h"
using namespace std;

int main()
{
    int num, choice, stop = 0;
    list list1, list2, list3;
    while (!stop)
    {
        cout << "\n\nMENU :";
        cout << "\n 1. Insert in List 1\n 2. Insert in List 2\n 3. Merge both Lists\n 4. Display all Lists\n 5. Exit" << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert : ";
            cin >> num;
            list1.InsertAsc(num);
            cout << "Insertion Succesful." << endl;
            break;

        case 2:
            cout << "Enter value to insert : ";
            cin >> num;
            list2.InsertAsc(num);
            cout << "Insertion Succesful." << endl;
            break;

        case 3:
            list3.Merge(list1, list2);
            cout << "Merge successful." << endl;
            break;

        case 4:
            cout << "\nList 1 : " << endl;
            list1.Display();
            cout << "\nList 2 : " << endl;
            list2.Display();
            cout << "\nList 3 : " << endl;
            list3.Display();
            break;

        case 5:
            stop = 1;
            cout << "Exitting code." << endl;
            break;

        default:
            cout << "Invalid choice. Enter again." << endl;
            break;
        }
    }
}
