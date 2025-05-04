#include <cstdio>

class List {
private:
    int arr[5];
    int size;
    
public:
    List() : size(0) {}
    
    void insertBeginning(int val);
    void insertEnd(int val);
    void insertPosition(int pos, int val);
    void deleteBeginning();
    void deleteEnd();
    void deletePosition(int pos);
    void search(int val);
    void display();
    void rotate(int k);
    void rotateOptimized(int k);
    void rotateUsingReverse(int k);
};


int main() {
    List list;
    int choice, val, pos, k;
    while (true) {
        std::printf("\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9. Rotate\n10. Exit\nEnter your choice: ");
        std::scanf("%d", &choice);
        switch (choice) {
            case 1:
                std::printf("Enter value: ");
                std::scanf("%d", &val);
                list.insertBeginning(val);
                break;
            case 2:
                std::printf("Enter value: ");
                std::scanf("%d", &val);
                list.insertEnd(val);
                break;
            case 3:
                std::printf("Enter position and value: ");
                std::scanf("%d %d", &pos, &val);
                list.insertPosition(pos, val);
                break;
            case 4:
                list.deleteBeginning();
                break;
            case 5:
                list.deleteEnd();
                break;
            case 6:
                std::printf("Enter position: ");
                std::scanf("%d", &pos);
                list.deletePosition(pos);
                break;
            case 7:
                std::printf("Enter value to search: ");
                std::scanf("%d", &val);
                list.search(val);
                break;
            case 8:
                list.display();
                break;
            case 9:
                std::printf("Enter k: ");
                std::scanf("%d", &k);
                list.rotateUsingReverse(k);
                break;
            case 10:
                return 0;
            default:
                std::printf("Invalid choice!\n");
        }
    }
    return 0;
}


void List::insertBeginning(int val) {
    if (size == 5) {
        std::printf("List is full!\n");
        return;
    }
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = val;
    size++;
}

void List::insertEnd(int val) {
    if (size == 5) {
        std::printf("List is full!\n");
        return;
    }
    arr[size++] = val;
}

void List::insertPosition(int pos, int val) {
    if (size == 5) {
        std::printf("List is full!\n");
        return;
    }
    if (pos < 1 || pos > size + 1) {
        std::printf("Invalid position!\n");
        return;
    }
    for (int i = size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;
    size++;
}

void List::deleteBeginning() {
    if (size == 0) {
        std::printf("List is empty!\n");
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void List::deleteEnd() {
    if (size == 0) {
        std::printf("List is empty!\n");
        return;
    }
    size--;
}

void List::deletePosition(int pos) {
    if (size == 0) {
        std::printf("List is empty!\n");
        return;
    }
    if (pos < 1 || pos > size) {
        std::printf("Invalid position!\n");
        return;
    }
    for (int i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void List::search(int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) {
            std::printf("Element found at position %d\n", i + 1);
            return;
        }
    }
    std::printf("Element not found!\n");
}

void List::display() {
    if (size == 0) {
        std::printf("List is empty!\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        std::printf("%d ", arr[i]);
    }
    std::printf("\n");
}

void List::rotate(int k) {
    k %= size;
    for (int i = 0; i < k; i++) {
        int temp = arr[size - 1];
        for (int j = size - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
}

void List::rotateOptimized(int k) {
    k %= size;
    int temp[5];
    for (int i = 0; i < size; i++) {
        temp[(i + k) % size] = arr[i];
    }
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
}

void List::rotateUsingReverse(int k) {
    k %= size;
    auto reverse = [](int arr[], int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    };
    reverse(arr, 0, size - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, size - 1);
}
