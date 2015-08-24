#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
	struct sockaddr_in addr;
	socklen_t addrlen;
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET; addr.sin_port = htons(12345);
	inet_pton(AF_INET, "10.80.45.149", &addr.sin_addr);
	int client_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	int conn_status = connect(client_fd, (struct sockaddr *)&addr, sizeof (addr));

	if (conn_status)
	{
		cout << "connection failed, reason is : " << strerror(errno) << endl;
	}
	else
	{
		cout << "connection from" << inet_ntoa(addr.sin_addr) << "Port:" << ntohs(addr.sin_port) << endl;        
		cout << "connection is finished." << endl;
		close(client_fd);
	}
	return 0;
}
