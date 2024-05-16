

#include <stdio.h>
#include <unistd.h>

int main() {

           printf("started!\n");
           fork();
           printf("completed!\n");
           return 0;
}
