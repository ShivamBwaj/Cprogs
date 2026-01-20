#include <stdio.h>

void merge(int *arr,int low,int mid,int high){
    int temp[100];
    int left=low;
    int right=mid+1;
    int poin=0;
    while(left<=mid&&right<=high){
        if(arr[left]<arr[right]){
            temp[poin]=arr[left];
            poin++;
            left++;
        }
        else{
            temp[poin]=arr[right];
            poin++;
            right++;
        }
    }
    while(left<=mid){
        temp[poin]=arr[left];
        poin++;
        left++;
    }
    while(right<=high){
        temp[poin]=arr[right];
        poin++;
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }

}

void mS(int *arr, int low, int high){  
    if(low == high){
        return;
    }
    int mid = (low + high) / 2;
    mS(arr, low, mid);
    mS(arr, mid + 1, high);
    merge(arr, low, mid, high);

}

int main(){
    
    int arr[] = {56, 44, 53, 23, 1};  
    int len = sizeof(arr) / sizeof(arr[0]);
    mS(arr,0,len-1);
    for (int j = 0; j < len; j++)
    {
        printf("%d\t",arr[j]);
    }
    
    return 0;

}
