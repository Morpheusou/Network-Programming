#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
using namespace std;

#define max_connections 10000

void server_handler(int servfd)
{
}

int main()
{
	struct sockaddr addr_;
	struct sockaddr_in addr;
	struct sockaddr_in client_addr;
	socklen_t sock_len = 0;
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(6977);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int fd_server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	bind(fd_server, (struct sockaddr*)&addr, sizeof(addr));
	listen(fd_server, max_connections);
	cout << "Server started\nlistening..." << endl;
	for (;;) {
		int fd_client = accept(fd_server, (struct sockaddr*)&client_addr, &sock_len);
		cout << "connection from " << inet_ntoa(client_addr.sin_addr) 
		     << "port : " << ntohs(client_addr.sin_port) << endl; 
		server_handler(fd_client);

		close(fd_client);
	}
	return 0;
}
