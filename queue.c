#include "queue.h"

#define nodeXor(a, b) (NODE *)((long)a ^ (long)b)

NODE *createNode(int key, int value) {
   NODE *node = (NODE *)malloc(sizeof(NODE));
   if (node != NULL) {
      node->key = key;
      node->value = value;
      node->next = NULL;
   }
   return node;
}

void freeNode(NODE *node) {
   if (node != NULL) {
      node->key = 0;
      node->value = 0;
      node->next = NULL;
      free(node);
      node = NULL;
   }
}

void printNode(NODE *node) {
   if (node != NULL) {
      printf("KEY: %d,\tVALUE: %d\n", node->key, node->value);
   } else
      printf("Could not find this node, are you sure about what you're doing?\n");   
}

QUEUE *createQueue() {
   QUEUE *queue = (QUEUE *)malloc(sizeof(QUEUE));
   if (queue != NULL) {
      queue->begin = NULL;
      queue->end = NULL;
      queue->size = 0;
   }
   return queue;
}

int empty(QUEUE *queue) {
   if (queue != NULL)
      return (!queue->begin && !queue->end);
   return -1;
}

void printQueueNor(QUEUE *queue) {
   if (!empty(queue)) {
      NODE *printer = queue->begin;
      NODE *prev = printer;
      NODE *aux;
      int counter = queue->size;

      printNode(printer);
      counter--;
      printer = printer->next; 

      do {
         printNode(printer);
         counter--;
         aux = printer;
         printer = nodeXor(printer->next, prev);
         prev = aux;
      } while (counter > 0);
   } else
      printf("Could not find queue, maybe it's empty or not created..?\n");
}

void printQueueInv(QUEUE *queue) {
   if (!empty(queue)) {
      NODE *printer = queue->end;
      NODE *prev = printer;
      NODE *aux;
      int counter = queue->size;

      printNode(printer);
      counter--;
      printer = printer->next; 

      do {
         printNode(printer);
         counter--;
         aux = printer;
         printer = nodeXor(printer->next, prev);
         prev = aux;
      } while (counter > 0);
   } else
      printf("Could not find queue, maybe it's empty or not created..?\n");
}

int push(QUEUE *queue, int key, int value) {
   if (queue != NULL) {
      NODE *node = createNode(key, value);
      if (empty(queue)) {
         queue->begin = node;
         queue->end = node;
      } else {
         if (queue->end->next)
            queue->end->next = nodeXor(queue->end->next, node);
         else
            queue->end->next = node;
         node->next = queue->end;
         queue->end = node;
      }
      queue->size++;
      return 1;
   }
   return 0;
}

NODE *pop(QUEUE *queue) {
   if (queue != NULL) {
      if (!empty(queue)) {
         NODE *aux = queue->begin;
         queue->begin = aux->next;
         if (queue->begin && queue->begin->next)
            queue->begin->next = nodeXor(queue->begin->next, aux);
         else
            queue->end = queue->begin;
         queue->size--;
         return aux;
      }
   }
   return NULL;
}

int destroyQueue(QUEUE *queue) {
   if (queue != NULL) {
      while (!empty(queue))
         freeNode(pop(queue));
      free(queue);
      return 1;
   }
   return 0;
}
