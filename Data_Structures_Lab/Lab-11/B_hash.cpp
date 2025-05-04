#include <iostream>
using namespace std;
#define size 10

class hashtable {
private:
    int values[size];
    int occupied[size];

    int hashfunction(int key) {
        return key % size;
    }

public:
    hashtable() {
        for (int i = 0; i < size; i++) {
            values[i] = -1;
            occupied[i] = false;
        }
    }

    void insert(int);
    void Delete(int);
    bool search(int);
    void display();
};

void hashtable::insert(int key) {
    int index = hashfunction(key);
    int i = 0;

    while (values[(index + i * i) % size] != -1 && occupied[(index + i * i) % size]) {
        i++;
        if (i == size) {
            cout << "Hash Table is Full!!" << endl;
            return;
        }
    }
    int newindex = (index + i * i) % size;
    values[newindex] = key;
    occupied[newindex] = true;
}

void hashtable::Delete(int key) {
    int index = hashfunction(key);
    int i = 0;

    while (values[(index + i * i) % size] != key && occupied[(index + i * i) % size]) {
        i++;
        if (i == size) {
            cout << "Key not found." << endl;
            return;
        }
    }
    if (values[(index + i * i) % size] == key) {
        values[(index + i * i) % size] = -1;
        occupied[(index + i * i) % size] = false;
    }
}

bool hashtable::search(int key) {
    int index = hashfunction(key);
    int i = 0;

    while (occupied[(index + i * i) % size]) {
        if (values[(index + i * i) % size] == key)
            return true;
        i++;
        if (i == size) {
            return false;
        }
    }
    return false;
}

void hashtable::display() {
    for (int i = 0; i < size; i++) {
        if (occupied[i] == false) {
            cout << "Empty" << endl;
        } else {
            cout << values[i] << endl;
        }
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
