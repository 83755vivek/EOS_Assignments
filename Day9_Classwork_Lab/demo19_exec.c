
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
          int ret, err, s;
          printf("parent started!\n");
          ret = fork();
          if(ret == 0) {
                  err = execl("/usr/bin/firefox", "firefox", "http://sunbeaminfo.in", NULL);
		//err = execlp("firefox", "firefox", "http://sunbeaminfo.in", NULL);
                char *args[]={"firefox", "http:sunbeaminfo.in", NULL};
             // err = execv("/usr/bin/firefox", args);
            // err = execv("firefox", args);
              if(err < 0) {
                      perror("exec() failed");
                      _exit(1);
                     }
              }
              else {
                    wait(&s);
                    printf("child exit status: %d\n", WEXITSTATUS(s));
               }
               printf("parent completed!\n");

              return 0;
}
