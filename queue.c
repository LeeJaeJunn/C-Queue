#include "queue.h"
#pragma warning(disable : 4996)
#include <stdio.h>

// 큐를 초기화
void initQueue(QUEUE *pq) { pq->front = pq->rear = 0; }

void enQueue(QUEUE *pq, char data) {
  pq->array[pq->rear] = data;
  pq->rear = (pq->rear + 1) % QUEUE_SIZE;
}

char deQueue(QUEUE *pq) {
  int save = pq->front;
  pq->front = (pq->front + 1) % QUEUE_SIZE;

  return pq->array[save];
}

// 비어있는 큐인지 검사. 비어있으면 TRUE, 요소가 있으면 FALSE를 반환
int isEmpty(QUEUE *pq) { return pq->front == pq->rear; }

void printQueue(QUEUE *pq);
void printQueueData(QUEUE *pq);

void main(void) {
  QUEUE q;
  char data;
  int menu;

  initQueue(&q);

  while (1) {
    printf("0. 종료 1. 추가 2. 삭제 3. 출력 - ");
    scanf("%d", &menu);
    fflush(stdin);

    if (menu == 0)
      break;

    switch (menu) {
    case 1:
      printf("문자 : ");
      scanf("%c", &data);

      enQueue(&q, data);
      break;

    case 2:
      if (isEmpty(&q))
        printf("에러 : 큐가 비었습니다!!\n");
      else
        printf("문자 : %c\n", deQueue(&q));
      break;

    case 3:
      printQueue(&q);
      printQueueData(&q);
      break;
    }
  }
}

// 큐에서 사용하는 배열의 내부 상태를 보여주는 함수
void printQueue(QUEUE *pq) {
  int i;

  if (pq->front <= pq->rear) {
    for (i = 0; i < QUEUE_SIZE; i++) {
      if (i >= pq->front && i < pq->rear)
        printf("%c ", pq->array[i]);
      else
        printf("* ");
    }
  } else {
    for (i = 0; i < QUEUE_SIZE; i++) {
      if (i >= pq->front || i < pq->rear)
        printf("%c ", pq->array[i]);
      else
        printf("* ");
    }
  }
  printf("\n");
}

// 큐에 저장된 순서대로 사용할수 있는 모든 데이터를 출력.
void printQueueData(QUEUE *pq) {
  int i;
  for (i = pq->front; i != pq->rear; i = (i + 1) % QUEUE_SIZE)
    printf("%c ", pq->array[i]);

  printf("\n");
}