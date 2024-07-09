#include<stdio.h>
#include<stdlib.h>
void main(){
    int pro,res,i,j,count=0,flag=0,k=0,exec=0;
    printf("Enter the no.of processes\n");
    scanf("%d",&pro);
    int visited[pro];
    int safeseq[pro];
    printf("Enter the no.of resources\n");
    scanf("%d",&res);
    int alloc[pro][res],max[pro][res],need[pro][res],available[res];
    printf("Enter the available resources\n");
    for(i=0;i<res;i++){
        scanf("%d",&available[i]);
    }
    for(i=0;i<pro;i++){
        visited[i]=0;
        printf("Enter the allocation of P%d\n",i);
        for(j=0;j<res;j++){
            scanf("%d",&alloc[i][j]);
        }
         printf("Enter the max of P%d\n",i);
        for(j=0;j<res;j++){
            scanf("%d",&max[i][j]);
        }
        for(j=0;j<res;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("Alloc Maximum  Need\n");
    for(i=0;i<pro;i++){
        for(j=0;j<res;j++){
            printf("%d ",alloc[i][j]);
        }
        printf("\t");
        for(j=0;j<res;j++){
            printf("%d ",max[i][j]);
        }
        for(j=0;j<res;j++){
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    while(count<pro){
        flag=0;
        for(i=0;i<pro;i++){
            exec=0;
            for(j=0;j<res;j++){
                if(need[i][j]<=available[j]){
                    exec++;
                }
            }
            if(exec==res&&visited[i]==0){
                for(j=0;j<res;j++){
                    available[j]=available[j]+alloc[i][j];
                }
                flag=1;
                visited[i]=1;
                count++;
                safeseq[k++]=i;
            }
        }
        if(flag==0){
            printf("No safe sequence\n");
            exit(0);
        }
    }
    printf("\nSafe Sequence:\n");
    printf("< ");
    for(i=0;i<pro;i++){
        printf("P%d ",safeseq[i]);

    }
    printf(">\n");

}
