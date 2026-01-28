#include <stdio.h>

int f(int arr[], int low, int high){
    int pivot = arr[low];
    int temp;
    int i = low;
    int j = high;

    while(i < j){
        while(arr[i] <= pivot && i <= high - 1){
            i++;
        }

        while(arr[j] > pivot && j >= low + 1){
            j--;   // ✅ FIXED HERE
        }

        if(i < j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void qS(int arr[], int low, int high){
    if(low < high){
        int partindex = f(arr, low, high);
        qS(arr, low, partindex - 1);
        qS(arr, partindex + 1, high);
    }
}

int main(){
    int arr[] = {4,3,5,2,1,6,8,9};
    int le = sizeof(arr)/sizeof(arr[0]);

    qS(arr, 0, le - 1);

    for(int i = 0; i < le; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
