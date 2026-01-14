#include <stdio.h>

int Line(int arr[],int len,int target){
    for(int l=0;l<len;l++){
        if(arr[l]==target){
            return l;
        }
    }
    return -1;
}

int main(){
    int a[]={67,45,3,76,32};
    int lo=sizeof(a)/sizeof(a[0]);
    int tar=0;
	printf("Enter target to searched");
    scanf("%d",&tar);
    int index= Line(a,lo,tar);
    printf("Index returned : %d",index);
    return 0;
}