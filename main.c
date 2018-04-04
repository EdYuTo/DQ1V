#include "queue.h"

int main(int argc, char *argv[ ]) {
   QUEUE *queue = createQueue();
   NODE *aux = NULL;

   for(int i = 0; i < 10; i++)
      push(queue, i, i);

   printQueueNor(queue);
   printf("\n");
   printQueueInv(queue);
   printf("\n");

   for (int i = 0; i < 20; i++) {
      aux = pop(queue);
      printNode(aux);
      freeNode(aux);
   }

   destroyQueue(queue);
   return 0;
}
