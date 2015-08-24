#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <errno.h>
using namespace std;

#define max_connections 10000

void server_handler(int servfd)
{
	cout << "server function activation" << endl;
}

int main()
{
	struct sockaddr addr_;
	struct sockaddr_in addr;
	struct sockaddr_in client_addr;
	socklen_t sock_len = 0;
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int fd_server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	bind(fd_server, (struct sockaddr*)&addr, sizeof(addr));
	listen(fd_server, max_connections);
	cout << "Server started\nlistening..." << endl;

	int client_fd[max_connections] = {0};
	for (int i = 0; i < max_connections; ++i) {
		client_fd[i] = accept(fd_server, (struct sockaddr*)&client_addr, &sock_len);

		if (-1 == client_fd[i]) {
			cout << "connection failed, reason is : " << strerror(errno) << endl;
		}else{	

			cout << "connection from " << inet_ntoa(client_addr.sin_addr) 
				<< "port : " << ntohs(client_addr.sin_port) << endl; 
			server_handler(client_fd[i]);

			close(client_fd[i]);
		}
	}
	return 0;
}
