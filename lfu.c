#include<stdio.h>
void main(){
    int no_req,no_fr,i,j,pgf=0,hit=0;
    printf("Enter the no.of requests and no of frames\n");
    scanf("%d%d",&no_req,&no_fr);
    int req[no_req],frame[no_fr],freq[no_fr],time[no_fr];
    for(i=0;i<no_fr;i++){
        frame[i]=-1;
        freq[i]=0;
        time[i]=0;
    }
    printf("Enter the requests\n");
    for(i=0;i<no_req;i++){
        scanf("%d",&req[i]);
    }
    printf("Page replacement using LFU:\n");
    for(i=0;i<no_req;i++){
        hit=0;
        printf("%d :",req[i]);
        for(j=0;j<no_fr;j++){
            if(frame[j]==req[i]){
                hit=1;
                freq[j]++;
                time[j]=i;
                break;
            }
        }
        if(hit==0){
            int minfreq=freq[0],minIndex=0,oldest=time[0];
            for(j=1;j<no_fr;j++){
                if(frame[j-1]==-1){
                    minIndex=j-1;
                    break;
                }
                else if(freq[j]<minfreq||(freq[j]==minfreq&&time[j]<oldest)){
                    minfreq=freq[j];
                    minIndex=j;
                    oldest=time[j];
                }
            }
            frame[minIndex]=req[i];
            freq[minIndex]=1;
            time[minIndex]=i;
            pgf++;
        }
        for(j=0;j<no_fr;j++){
            printf("%d\t",frame[j]);
        }
        printf("\n");

    }
    printf("Page fault=%d\n",pgf);
}
