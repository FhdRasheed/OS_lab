#include<stdio.h>
void main(){
    int limit,i,j,temp;
    printf("Enter the no.of processes\n");
    scanf("%d",&limit);
    int pid[limit],bt[limit],pri[limit];
    printf("Enter process id,Burst time and priority\n");
    for(i=0;i<limit;i++){
        printf("Enter process id\n");
        scanf("%d",&pid[i]);
        printf("Enter burst time\n");
        scanf("%d",&bt[i]);
        printf("Enter the priority\n");
        scanf("%d",&pri[i]);
    }

    for(i=0;i<limit;i++){
        for(j=i+1;j<limit;j++){
            if(pri[i]>pri[j]){
                temp=bt[j];
                bt[j]=bt[i];
                bt[i]=temp;
                temp=pid[j];
                pid[j]=pid[i];
                pid[i]=temp;
                temp=pri[j];
                pri[j]=pri[i];
                pri[i]=temp;

            }

        }
    }
    int wt[limit],tat[limit];
    wt[0]=0;
    tat[0]=bt[0];

    for(i=1;i<limit;i++){
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=tat[i-1]+bt[i];

    }
    int tot_wt,tot_tat;
    tot_wt=0;
    tot_tat=0;
    for(i=0;i<limit;i++){
        tot_wt=tot_wt+wt[i];
        tot_tat=tot_tat+tat[i];

    }
   

    printf("process  Burst  Priority  WT  TAT\n");
    for(i=0;i<limit;i++){
        printf("  %d\t  %d\t  %d\t  %d    %d\n",pid[i],bt[i],pri[i],wt[i],tat[i]);
    }
        printf("Total waiting time:%d\n",tot_wt);
        printf("Total TAT:%d\n",tot_tat);
         float avg_wt,avg_tat;
    avg_wt=(float)tot_wt/limit;
    avg_tat=(float)tot_tat/limit;
        printf("Average WT:%f\n",avg_wt);
        printf("Average TAT:%f\n",avg_tat);


}
