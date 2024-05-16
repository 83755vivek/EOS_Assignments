#include "demo36.h"

int main()  {
      int mqid, ret;
       msg_t m2;
      // access message queue
      mqid = msgget(MQ_KEY, 0);
      if(mqid < 0)  {
             perror("msgget() failed");
             _exit(1);
    }

      // receive message
      printf("p2: waiting for message...\n");
      ret = msgrcv(mqid, &m2, sizeof(m2.str), 11, 0);
      printf("p2: message received: %s\n", m2.str);

    //  destory message queue
      msgctl(mqid, IPC_RMID, NULL);
   return 0;


}




