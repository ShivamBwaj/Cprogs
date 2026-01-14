#include <stdio.h>
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int n, key;
    printf("Enter number of student IDs: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter student IDs:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter ID to search: ");
    scanf("%d", &key);

    int result = linearSearch(arr, n, key);
    if (result != -1)
        printf("Student ID found at index %d", result);
    else
        printf("Student not registered");

    return 0;
}
