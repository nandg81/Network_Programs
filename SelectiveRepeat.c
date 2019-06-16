#include<stdio.h>
#include<stdlib.h>
int main()
{
    int windowsize,sent=0,ack,i,ch;
    printf("Enter window size\n");
    scanf("%d",&windowsize);
    while(1)
    {
        for( i = 0; i < windowsize; i++)
        {
            printf("Frame %d (sequence no: %d) has been transmitted.\n",sent,i);
            sent++;
            if(sent == windowsize)
                break;
        }    
        ch=1;
        while(ch==1)
        {
            printf("\nAre there any frames for which acknowledgement was not received?(1-yes,2-no,0-exit\n");
            scanf("%d",&ch); 
            if(ch == 1)                       
            {
                printf("\nPlease enter the frame for which Acknowledgement was not received.\n");
                scanf("%d",&ack);
                printf("Frame %d has been retransmitted.\n",ack);
            }
            else if(ch==0)
                exit(0);
        }        
    }
    return 0;
}
