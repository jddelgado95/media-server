#include <netinet/in.h> //structure for storing address information
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> //for socket APIs
#include <sys/types.h>

int main(int argc, char const* argv[])
{
    // Creates the client socket call.
    // Domain: IPv4 (AF_INET)
    // Type of socket: TCP/UDP (SOCK_STREAM)
    // Protocol: IP (0)
	int sockD = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in servAddr;

	servAddr.sin_family = AF_INET;
	servAddr.sin_port
		= htons(9001); // use some unused port number
	servAddr.sin_addr.s_addr = INADDR_ANY;

    // Connects to a remote address. 
    // Specify the IP ADDRESS and PORT 
	int connectStatus
		= connect(sockD, (struct sockaddr*)&servAddr,
				sizeof(servAddr));

	if (connectStatus == -1) {
		printf("Error...\n");
	}

	else {
		char strData[255];
        // Data is retrieved here. Received data can be stored in a file or into a string. 
		recv(sockD, strData, sizeof(strData), 0);

		printf("Message: %s\n", strData);
	}

	return 0;
}

