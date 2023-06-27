#include <stdio.h>
#include <stdlib.h>
#include "Circular.h"

void initQueue(Queue *q) {
	q->front = 7;
	q->rear = 6;
	int i;
	for(i = 0; i < MAX; ++i) {
		q->elems[i] = EMPTY;
	}
}

void enqueue(Queue *q, int item) {
	if(!isFull(*q)) {
		q->rear = (q->rear + 1) % MAX;
		q->elems[q->rear] = item;
	}
}

void dequeue(Queue *q) {
	if(!isEmpty(*q)) {
		q->elems[q->front] = EMPTY;
		q->front = (q->front = 1) % MAX;
	}
}

int front(Queue q) {
	if(!isEmpty(q)) {
		return q.elems[q.front];
	}
	return EMPTY;
}

bool isEmpty(Queue q) {
	return (q.rear + 1) % MAX == q.front;
}

bool isFull(Queue q) {
	return (q.rear + 2) % MAX == q.front;
}

void visualize(Queue q) {
	int i;
	
	printf("%5s | %5s | %s\n", "INDEX", "VALUE", "POSITION");
	printf("------------------------\n");
	for(i = 0; i < MAX; ++i) {
		printf("%5d | ", i);
		if(q.elems[i] != EMPTY) {
			printf("%5d | ", q.elems[i]);
		} else {
			printf("%5s | ", " ");
		}
		if(i == q.front) {
			printf("Front");
		}
		if(i == q.rear) {
			printf("Rear");
		}
		printf("\n");
	}
	printf("------------------------\n");
}

void display(Queue q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    
    int i = q.front;
    printf("Elements of the queue (from front to rear):\n");
    
    while (i != q.rear) {
        printf("%d ", q.elems[i]);
        i = (i + 1) % MAX;
    }
    
    printf("%d\n", q.elems[q.rear]);
}

/*
---first Occurence
---use only the Queue operations no element traversals
*/
bool removeItem(Queue *q, int item) {
    Queue temp;
    initQueue(&temp);
    int found = 0;

    while (!isEmpty(*q)) {
        int currItem = front(*q);
        dequeue(q);

        if (currItem == item && !found) {
            found = 1;
            continue;
        }

        enqueue(&temp, currItem);
    }

    while (!isEmpty(temp)) {
        int currItem = front(temp);
        dequeue(&temp);
        enqueue(q, currItem);
    }

    return found;
}



/*
---removes all Even and returns all deleted item stored in Q
*/
Queue removeEven(Queue *q);

/*
---doubles the value in Q that is a multiple of the give value and
	return how many values have been change
*/
int doubleTheValue(Queue *q, int value);


