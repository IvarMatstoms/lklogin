#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <netinet/in.h>

#include <string.h>

int main(int argc, char *argv[]) {
   int sockfd, portno, n;
   struct sockaddr_in serv_addr;
   struct hostent *server;

   //char buffer[256];


   portno = atoi("6082");

   /* Create a socket point */
   sockfd = socket(AF_INET, SOCK_STREAM, 0);

   if (sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
   }

   server = gethostbyname("surf.linkoping.se");

   if (server == NULL) {
      fprintf(stderr,"ERROR, no such host\n");
      exit(0);
   }

   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
   serv_addr.sin_port = htons(portno);

   if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
      perror("ERROR connecting");
      exit(1);
   }

   char buffer[] = "POST /php/uid.php?vsys=1&url=http://google.se HTTP/1.1\nHost: surf.linkoping.se:6082\nConnection: close\nContent-Length: 68\nCache-Control: max-age=0\nOrigin: https://surf.linkoping.se:6082\nUpgrade-Insecure-Requests: 1\nUser-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.87 Safari/537.36\nContent-Type: application/x-www-form-urlencoded\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\nDNT: 1\nReferer: https://surf.linkoping.se:6082/php/uid.php?vsys=1&url=http://google.se\nAccept-Encoding: gzip, deflate, br\nAccept-Language: sv-SE,sv;q=0.8,en-US;q=0.6,en;q=0.4\nCookie: PHPSESSID=c7f0d7b1b03a70c3d8b374ccf7fda556\n inputStr=&escapeUser=username&user=username&passwd=password&ok=Login";
   n = write(sockfd, buffer, strlen(buffer));

   if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
   }
   if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
   }

   //printf("%s\n",buffer);
   return 0;
}
