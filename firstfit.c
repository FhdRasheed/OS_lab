#include<stdio.h>
void main(){
    int pro,memblok,i,j;
    printf("enter no of processes and memory blocks\n");
    scanf("%d%d",&pro,&memblok);
    struct memory{
        int size;
        int alloc;
    }m[memblok];
    struct process{
        int psize;
        int flag;
    }p[pro];
    for(i=0;i<memblok;i++){
        printf("Enter the size of memory block %d\n",i+1);
        scanf("%d",&m[i].size);
        m[i].alloc=0;
    }
    for(i=0;i<pro;i++){
        printf("Enter the size of process %d\n",i+1);
        scanf("%d",&p[i].psize);
        p[i].flag=0;
    }

    for(i=0;i<pro;i++){
        for(j=0;j<memblok;j++){
            if(p[i].flag==0){
                if(p[i].psize<=m[j].size){
                    if(m[j].alloc==1){
                        continue;
                    }
                    else{
                        m[j].alloc=1;
                        p[i].flag=1;
                        printf("Process %d is allocated to %d block\n",p[i].psize,m[j].size);
                    }
                }
            }
        }
    } 
        for(i=0;i<pro;i++){
            if(p[i].flag==0){
                printf("There is no space for %d process\n",p[i].psize);
            }
        }
    }
