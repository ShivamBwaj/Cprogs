#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>



int main(){
    int ch;
    do{
        printf("\n1. Insert \n 2.Update\n 3.Delete\n 4.Traverse \n 5.Search\n6.Exit");
        printf("\nEnter Your choice \n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Insert");
                break;
            case 2:
                printf("Update");
                break;
            case 3:
                printf("Delete");
                break;
            case 4:
                printf("Traverse");
                break;
            case 5:
                printf("Search");
                break;
            
        }
        
    }while(ch!=6);
}