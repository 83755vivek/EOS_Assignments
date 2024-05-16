


#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main()  {
          int arr[2], ret;
          char datawr[32], datard[32];
          ret = pipe(arr);
          if(ret < 0)  {
                   perror("pipe() failed");
                   _exit(1);
              }
           
           printf("enter a string: ");
          scanf("%s", datawr);
          ret = write(arr[1], datawr, strlen(datawr)+1);
          printf("data written in pipe: %d bytes\n", ret);

          ret = read(arr[0], datard, sizeof(datard));
          printf("data read from pipe: %d bytes -- %s\n", ret, datard);
           
          close(arr[1]);
          close(arr[0]);
         return 0;
}
