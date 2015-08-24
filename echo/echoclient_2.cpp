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
	addr.sin_family = AF_INET; addr.sin_port = htons(6977);
	inet_pton(AF_INET, "10.80.45.149", &addr.sin_addr);

	for (int i = 0; i < 10000; ++i)
	{	
        	int client_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		int conn_fd = connect(client_fd, (struct sockaddr *)&addr, sizeof (addr));
		cout << "connection " << i+1 << "is success" << endl;
	close(conn_fd);
	}

	
	
        
        cout << "connection is finished." << endl;
	return 0;
}
