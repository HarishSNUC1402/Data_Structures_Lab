#include <cstdio>
#include "sort.h"

// LINEAR SEARCH 
int linearSearch(int arr[], int num, int target) {
    for (int i = 0; i < num; i++) {
        if (arr[i] == target) {
            return i;  
        }
    }
    return -1;  
}

// BINARY SEARCH
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;  
        }
        if (arr[mid] < target) {
            left = mid + 1;  
        } else {
            right = mid - 1;  
        }
    }
    return -1;  
}

int main() {
    int num;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &num);

    int arr[num];
    printf("Enter %d elements: ", num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    int choice, target, result;

    do {
        printf("\nMenu:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Sorting the array using Bubble Sort...\n");
                bubblesort(arr, num);

                printf("Sorted array: ");
                for (int i = 0; i < num; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n Enter the element to search (Linear Search): ");
                scanf("%d", &target);
                result = linearSearch(arr, num, target);
                if (result != -1)
                    printf("Element found at index: %d\n", result);
                else
                    printf("Element not found\n");
                break;

            case 2:
                printf("Sorting the array using Bubble Sort...\n");
                bubblesort(arr, num);

                printf("Sorted array: ");
                for (int i = 0; i < num; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\nEnter the element to search (Binary Search): ");
                scanf("%d", &target);

                result = binarySearch(arr, 0, num - 1, target);
                if (result != -1)
                    printf("Element found at index: %d\n", result);
                else
                    printf("Element not found\n");
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}