#include<stdio.h>
void main(){
     int limit,i,tq;
    printf("Enter the no.of processes\n");
    scanf("%d",&limit);
    int pid[limit],bt[limit],rt[limit],wt[limit],tat[limit];
    printf("Enter process id & Burst time\n");
    for(i=0;i<limit;i++){
        printf("Enter process id\n");
        scanf("%d",&pid[i]);
        printf("Enter burst time\n");
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }
    printf("enter the time quantum\n");
    scanf("%d",&tq);
    int time=0;
    int completed=0;
    while(completed<limit){
        for(i=0;i<limit;i++){
            if(rt[i]>0){
                if(rt[i]>tq){
                    time=time+tq;
                    rt[i]=rt[i]-tq;
                }
                else{
                    time=time+rt[i];
                    wt[i]=time-bt[i];
                    rt[i]=0;
                    completed++;
                    tat[i]=time;
                }
            }
        }
    }
     int tot_wt,tot_tat;
    tot_wt=0;
    tot_tat=0;
    for(i=0;i<limit;i++){
        tot_wt=tot_wt+wt[i];
        tot_tat=tot_tat+tat[i];

    }
   

    printf("process  Burst  WT  TAT\n");
    for(i=0;i<limit;i++){
        printf("  %d\t  %d\t%d   %d\n",pid[i],bt[i],wt[i],tat[i]);
    }
        printf("Total waiting time:%d\n",tot_wt);
        printf("Total TAT:%d\n",tot_tat);
         float avg_wt,avg_tat;
    avg_wt=(float)tot_wt/limit;
    avg_tat=(float)tot_tat/limit;
        printf("Average WT:%f\n",avg_wt);
        printf("Average TAT:%f\n",avg_tat);


}
