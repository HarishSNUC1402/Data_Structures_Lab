#include<cstdio>
void bubblesort(int arr[],int num);
void bubblesort(int arr[],int num){
    for(int i=0;i<num-1;i++){
        for(int j=0;j<num-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
        }
    }
    printf("the array after sorting is : ");
    for(int k=0;k<num;k++){
        printf("%d ",arr[k]);
    }
}
void selectionsort(int arr[],int num){
    for(int i=0;i<num -1;i++){
        for(int j=i+1;j<num ;j++){
            if(arr[i]>arr[j]){
                int temp;
                temp=arr[j];
                arr[j]=arr[j];
                arr[i]=temp;
            }
        }
    }   
printf("the array after sorting is : ");
    for(int k=0;k<num;k++){
        printf("%d ",arr[k]);
    }
}
void insertionsort(int arr[],int num){
    for(int i=1;i<num;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]) {
            int temp;
            temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }

}

int main(){
    int arr[100],num,choice;
    int flag=1;
    while(flag==1){
        
        printf("\nMENU\n 1.Bubblesort\n 2.Selectionsort\n 3.Insertion sort\n 4.Exit\n");
        printf(" enter your choice:");
        scanf("%d",&choice);
        if(choice>0 && choice<4){
            printf("enter the number of elements:");
            scanf("%d",&num);
            for(int i=0;i<num;i++){
                printf(" enter the elements:");
                scanf("%d",&arr[i]);

            }
        }
        switch(choice){
            case 1:bubblesort(arr,num);
                   break;
            case 2: selectionsort(arr,num);
                    break;
            case 3: insertionsort(arr,num) ;
                    break;
            case 4: printf("exiting the program\n");
                    flag=0;
                    break;
            default: 
                    printf("invalid choice , try again");
                    

                
                   
        }
    }
}