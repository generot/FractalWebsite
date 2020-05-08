#include "head.h"

typedef struct addrinfo addrinfo;
int main(int argc, char**argv){
    WSADATA wsd;

    WSAStartup(MAKEWORD(2,2),&wsd);
    HINSTANCE lib = LoadLibraryA("ws2_32");

    int WSAAPI (*getinfo)(const char*,const char*,const struct addrinfo*,
		        struct addrinfo**) = GetProcAddress(lib,"getaddrinfo");

    SOCKET sock;
    addrinfo adInf, *list;

    ZeroMemory(&adInf,sizeof(addrinfo));
    adInf.ai_protocol = IPPROTO_TCP;
    adInf.ai_socktype = SOCK_STREAM;
    adInf.ai_family = AF_UNSPEC;

    if(getinfo(argv[1],argv[2],&adInf,&list) != 0){
        printf("Info gathering error: %d",WSAGetLastError());
        WSACleanup();
        return EXIT_SUCCESS;
    }

    for(addrinfo *inf = list; inf != NULL; inf = inf->ai_next){
        if((sock = socket(inf->ai_family, inf->ai_socktype, inf->ai_protocol)) != INVALID_SOCKET){
            if(connect(sock,inf->ai_addr,inf->ai_addrlen) == SOCKET_ERROR){
                sock = INVALID_SOCKET;
                continue;
            }
        }
        else {
            printf("Socket init. error: %d",WSAGetLastError());
            WSACleanup();
            return EXIT_SUCCESS;
        }
        break;
    }

    if(sock == INVALID_SOCKET){
        printf("Socket error: %d", WSAGetLastError());
        WSACleanup();
        return EXIT_SUCCESS;
    }

    char buffer[MAX_BUFFSIZE], rcv[RCV_BUFFERSIZE];
    for(;;){
        ZeroMemory(buffer,MAX_BUFFSIZE);
        scanf("%s",buffer);

        buffer[MAX_BUFFSIZE-1] = '\0';
        if(send(sock, buffer, (int)strlen(buffer), 0) < 0){
            printf("Sending error: %d",WSAGetLastError());
            WSACleanup();
            break;
        }

        ZeroMemory(rcv,RCV_BUFFERSIZE);
        rcv[RCV_BUFFERSIZE-1] = '\0';

        // int res = recv(sock, rcv, RCV_BUFFERSIZE, 0);

        // if(res < 0){
        //     printf("Receiving error: %d",WSAGetLastError());
        //     WSACleanup();
        //     break;
        // } else if(res > 0) printf("%s",rcv);
    }

    closesocket(sock);
    FreeLibrary(lib);
    WSACleanup();
    return EXIT_SUCCESS;
}