
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
     int i;
     for(i=0; i<argc; i++)
    {
           puts(argv[i]);
           sleep(1);
     }

  return 0;



}

// cmd> ./demo17.out one two three four five
