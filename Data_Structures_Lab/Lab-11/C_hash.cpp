#include <iostream>
#include <list>
using namespace std;
#define size 10

class hashtable {
private:
    list<int> values[size];

public:
    void insert(int);
    void Delete(int);
    bool search(int);
    void display();
};

void hashtable::insert(int key) {
    int index = key % size;
    values[index].push_back(key);
}

void hashtable::Delete(int key) {
    int index = key % size;
    values[index].remove(key);
}

bool hashtable::search(int key) {
    int index = key % size;
    for (auto it = values[index].begin(); it != values[index].end(); it++) {
        if (*it == key)
            return true;
    }
    return false;
}

void hashtable::display() {
    for (int i = 0; i < size; i++) {
        cout << "Bucket " << i << ": ";
        for (auto it = values[i].begin(); it != values[i].end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
}

int main() {
    hashtable ht;
    int val, ch;
    while (true) {
        cout << "\nMENU\n";
        cout << "\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter value to be inserted: ";
                cin >> val;
                ht.insert(val);
                break;
            case 2:
                cout << "Enter value to be deleted: ";
                cin >> val;
                ht.Delete(val);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> val;
                if (ht.search(val))
                    cout << "Key found." << endl;
                else
                    cout << "Key not found." << endl;
                break;
            case 4:
                cout << "The values in the Hash table: " << endl;
                ht.display();
                break;
            case 5:
                cout << "Exiting.." << endl;
                return 0;
                break;
            default:
                cout << "Invalid Input! Try Again." << endl;
                break;
        }
    }
}
