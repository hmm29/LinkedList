#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
	int data;
	struct ListNode *next;
};

void InsertInLinkedList(struct ListNode **head, int data, int position) {
	int k = 1;
	struct ListNode *p, *q, *newNode;
	newNode = malloc(sizeof(struct ListNode));
	if(!newNode) {
		printf("Memory Error");
		return;
	}
	newNode->data = data;
	printf("New node data: %d \n", newNode->data);
	p = *head;
	if(position == 1){
		newNode->next = p;
		*head = newNode;
	}
	else {
		while((p != NULL) && (k <= position-1)) {
			k++;
			q = p;  /* q is a way to keep track of prev node */
			printf("This node has data: %d \n", q->data);
			p = p->next;
		}
		if (p == NULL) {
			newNode->next = NULL;
			q->next = newNode;
		}
		else {
			q->next = newNode;
			newNode->next = p;
		}
		printf("This node has data: %d \n", newNode->data);
	}
}



int main(int argc, char **argv) {		
	struct ListNode *head;
	head = malloc(sizeof(struct ListNode));
	head->data = 19;
	head->next = NULL;
	struct ListNode **header = &head;
	InsertInLinkedList(header, 8, 2);
	InsertInLinkedList(header, 9, 3);
	InsertInLinkedList(header, 10, 4);
	return 0;
}
