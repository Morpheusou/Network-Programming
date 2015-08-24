#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
using namespace std;

#define max_connections 10000

void client_handler(int client_fd)
{
	cout << "client function activation" << endl;
}

int main()
{
	struct sockaddr_in addr;
	socklen_t addrlen;
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET; addr.sin_port = htons(6977);
	inet_pton(AF_INET, "10.80.45.149", &addr.sin_addr);

	int client_fd[max_connections] = {0};

	for (int i = 0; i < max_connections; ++i)
	{	
		client_fd[i] = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		int conn_status = connect(client_fd[i], (struct sockaddr *)&addr, sizeof (addr));
		if (conn_status)
		{
			cout << "connection failed, reason is : " << strerror(errno) << endl;
		}
		else
		{
			cout << "connection " << i+1 << "is success" << endl;
			client_handler(client_fd[i]);
			close(client_fd[i]);
			cout << "connection is finished." << endl;
		}
		return 0;
	}
}
