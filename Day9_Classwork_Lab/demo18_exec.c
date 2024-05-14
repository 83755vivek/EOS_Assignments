



#include <stdio.h>
#include <sys/wait.h>

int main() {
          int ret, err, s;
          printf("parent started!\n");
          ret = fork();
          if(ret == 0) {

            //child process
            //err = execl("/home/nilesh/mar-24/desd/eos/Day09/demo17_child.out", "demo17.out", "one", "two", "three", "four", "five", NULL);")

          char *args[]={"demo17_child.out", "one", "two", "three", "four", "five", NULL};
          err = execv("/home/admin1/Desktop/EOS_Lab/Day9_lab/demo17_child.out", args);
          if(err < 0) {
                 perror("exec() failed");
                 _exit(1);
			}
		}
                else {
                 //parent process
                wait(&s);
                printf("child exit status: %d\n", WEXITSTATUS(s));
              }
                 printf("parent completed!\n");
                 return 0;

}
