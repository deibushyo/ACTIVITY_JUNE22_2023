#include <stdio.h>
#include <stdlib.h>
#include "Circular.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue myQueue;
	int choice;
	String menuOption[8] = {"Enqueue", "Dequeue", "isEmpty", 
	"isFull", "Display", "Visualize", "Front", "Remove Item"};
	
	initQueue(&myQueue);
	
	int i, x, value;
	do {
		system("cls");
		printf("MENU\n");
		for(i = 0; i < 8; ++i) {
			printf("[%d] %s\n", i+1, menuOption[i]);
		}
		printf("\nEnter your choice <0 to EXIT>: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("Enqueue\n");
				printf("Enter a number: ");
				scanf("%d", &value);
				enqueue(&myQueue, value);
				//visualize(myQueue);
				break;
			case 2:
				printf("Dequeue\n");
				dequeue(&myQueue);
				break;
			case 3:
				//printf("Check if empty\n");
				if(isEmpty(myQueue)) {
					printf("EMPTY\n");
				}
				break;
			case 4:
				//printf("Check if full\n");
				if(isFull(myQueue)) {
					printf("FULL\n");
				}
				break;
			case 5:
				printf("Display queue\n");
				display(myQueue);
				break;
			case 6:
				printf("Visualize Queue\n");
				visualize(myQueue);
				break;
			case 7:
				printf("Front\n");
				printf("The value at Front: %d", front(myQueue));
				break;
			case 8:
				if(removeItem(&myQueue, 35)) {
					printf("Remove Succesfully\n");
				}
				break;
			case 0:
				printf("Thank you!");
				break;
			default:
				printf("Invalid choice...\n");
		}
		printf("\n");
		system("pause");
	} while(choice != 0);
	printf("\nBye!!\n");
	
	
	//visualize(myQueue);
		
	return 0;
}
