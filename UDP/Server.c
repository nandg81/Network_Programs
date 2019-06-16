#include"sys/socket.h"
#include"netinet/in.h"
#include"stdio.h"
#include"string.h"
#include"stdlib.h"

int main()
{
	char buf[100];
	int k,len;
	int sock_desc,connfd;
	struct sockaddr_in serv,cli;
	memset(&serv,0,sizeof(serv));
	sock_desc=socket(AF_INET,SOCK_DGRAM,0);
	if(sock_desc==-1)
	{
		printf("Error in socket creation");
		exit(1);
	}
	serv.sin_family=AF_INET;
	serv.sin_addr.s_addr=INADDR_ANY;
	serv.sin_port=htons(3031);
	if ((bind(sock_desc,(struct sockaddr*)&serv,sizeof(serv))) != 0) 
	{         
		printf("socket bind failed...\n"); 
	        exit(0); 
    	} 
    	else
        	printf("Socket successfully binded\n"); 
	bzero(buf,sizeof(buf)); 
	recvfrom(sock_desc, (char *)buf, 1024,  MSG_WAITALL, ( struct sockaddr *) &cli,&len); 
	printf("%s",buf);
	close(sock_desc);
	exit(0);
	return 0;	
}
