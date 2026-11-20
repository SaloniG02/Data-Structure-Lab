// queue implementation using array

#include <stdio.h>
int F=-1,R=-1;
int size;
int q[20];

void Enqueue(){
    int data;
   if((R+1)%size==F){
        printf("\nQueue OVERFLOW\n");
    }else{
        printf("ENTER DATA TO ENQUEUE:");
        scanf("%d",&data);

        if(F==-1){
            F=0;
            R=0;
            q[R]=data;
        }else{
            R=(R+1)%size;
            q[R]=data;
        }
    }
}

void Dequeue(){
    int  data;
    if(F==-1){
        printf("\nQUEUE UNDERFLOW\n");
        return ;
    }else{
        data=q[F];
        if(F==R){
            F=-1;
            R=-1;
        }else{
            F=(F+1)%size;
        }
        printf("%d is deleted",data);
    }
}

void Trav()
{
    int i;
    if(F==-1){
        printf("\nQUEUE UNDERFLOW\n");
        return ;
    }else{
        if(F==R+1){
            for(i=F;i<size;i++){
                printf("%d",q[i]);
            }
                for(i=0;i<=R;i++){
                    printf("%d",q[i]);
                }
        }else{
            for (i=F;i<R;i++){
                printf("%d",q[i]);
            }
        }
    }
}

int main()
{
    int choice;
    printf("Enter queue size: ");
    scanf("%d", &size);
    while (1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Trav");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                Enqueue();
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Trav();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}



