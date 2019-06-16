#include"sys/socket.h"
#include"netinet/in.h"
#include"stdio.h"
#include"string.h"
#include"stdlib.h"

int main()
{
	char buf[100];
	int k,n;
	int sock_desc;
	struct sockaddr_in serv;
	memset(&serv,0,sizeof(serv));
	sock_desc=socket(AF_INET,SOCK_DGRAM,0);
	if(sock_desc==-1)
	{
		printf("Error in socket creation");
		exit(1);
	}
	serv.sin_family=AF_INET;
	serv.sin_addr.s_addr=inet_addr("127.0.0.1");
	serv.sin_port=htons(3031);
	k=connect(sock_desc,(struct sockaddr*)&serv,sizeof(serv));
	if(k==-1)
	{
		printf("Error in connecting to server");
		exit(1);	
	}
	bzero(buf, sizeof(buf));
	printf("Enter the data to be sent: ");
	scanf("%s",buf);
	sendto(sock_desc, buf, strlen(buf),MSG_CONFIRM, (const struct sockaddr *) &serv,sizeof(serv)); 
	close(sock_desc);
	return(0);
}
