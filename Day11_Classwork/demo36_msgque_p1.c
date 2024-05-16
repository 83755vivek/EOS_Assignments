#include "demo36.h"


int main()  {
       int mqid, ret;
       msg_t m1;
     // create message queue
       mqid = msgget(MQ_KEY, IPC_CREAT | 0600);
       if(mqid < 0) {
              perror("msgget() failed");
              _exit(1);
        }
         
      // send message
       printf("p1: enter a string: ");
       scanf("%s", m1.str);

       m1.type = 11;

       ret = msgsnd(mqid, &m1, sizeof(m1.str), 0);
       printf("p1: message sent: %d\n", ret);
       return 0;
}

