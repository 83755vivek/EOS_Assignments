


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main()  {
         int arr[2], ret, s;
         char datawr[32], datard[32];
         ret = pipe(arr);
         if(ret < 0)  {
                perror("pipe() failed");
               _exit(1);
          }

          ret = fork();
          if(ret == 0) {
              // child  -- write process
              close(arr[0]);  //close read fd
              printf("child: enter a string: ");
              scanf("%s", datawr);
              ret = write(arr[1], datawr, strlen(datawr)+1);  // write data in pipe
              printf("child: data written in pipe: %d bytes\n", ret);
              close(arr[1]);   // close write fd 
            }
            else  {
                 // parent -- reader process
                 close(arr[1]);  // close write fd
                 printf("parent: waiting for data...\n");
                 ret = read(arr[0], datard, sizeof(datard));  // read data from pipe

                printf("parent: data read from pipe: %d bytes -- %s\n", ret, datard);
                close(arr[0]);   //close read fd
                waitpid(-1, &s, 0);

        }
        return 0;
}
