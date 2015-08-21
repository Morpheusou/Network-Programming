#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
	struct sockaddr_in addr;
	socklen_t addrlen;
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(6977);
	inet_pton(AF_INET, "192.168.237.128", &addr.sin_addr);
	int client_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	int conn_fd = connect(client_fd, (struct sockaddr *)&addr, sizeof (addr));

	return 0;
}
