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
	sock_desc=socket(AF_INET,SOCK_STREAM,0);
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
   	if ((listen(sock_desc, 5)) != 0) 
	{ 
        	printf("Listen failed\n"); 
        	exit(0); 
    	} 
    	else
        	printf("Server listening\n"); 
	len=sizeof(cli);
	connfd = accept(sock_desc,(struct sockaddr*)&cli,&len); 
 	if (connfd < 0) 	
	{ 
        	printf("Server acccept failed\n"); 
        	exit(0); 
    	} 
    	else
      	{  
		printf("Server acccepted the client\n"); 
		bzero(buf,sizeof(buf)); 
		read(connfd,buf,100);
		printf("Message from client: %s",buf);
		close(sock_desc);
		exit(0);
		return 0;
	}
}
