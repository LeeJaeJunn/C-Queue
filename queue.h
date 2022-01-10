#pragma once

enum { QUEUE_SIZE = 5 };

typedef struct {
  char array[QUEUE_SIZE];
  int front, rear;
} QUEUE;

void initQueue(QUEUE *pq);
void enQueue(QUEUE *pq, char data);
char deQueue(QUEUE *pq);
int isEmpty(QUEUE *pq);