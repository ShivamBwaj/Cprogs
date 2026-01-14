#include <stdio.h>

int Bine(int arr[],int len,int target){
    int l,r;
    l=0;
    r=len-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if (target==arr[mid])
        {
            return mid;
        }
        else if (target<arr[mid])
        {
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}

int main(){
    int a[]={23,43,54,67,88};
    int lo=sizeof(a)/sizeof(a[0]);
    int tar=0;
	printf("Enter target to searched");
    scanf("%d",&tar);
    int index= Bine(a,lo,tar);
    printf("Index returned : %d",index);
    return 0;
}