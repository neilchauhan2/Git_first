#include <stdio.h>
#include <stdlib.h>
void main(){

	struct Node{
		int data;
		struct Node *next;
	};

	void printList(struct Node *x){
		while(x != NULL){
			printf("%d ",x->data);
			x = x-> next;
		}
	}

	int reverseList(struct Node *x){
		struct Node *curr = (struct Node*)malloc(sizeof(struct Node));
		struct Node *pre = (struct Node*)malloc(sizeof(struct Node));
		struct Node *nex = (struct Node*)malloc(sizeof(struct Node));
		curr = x;
		pre = nex = NULL;
		while(curr != NULL){
			nex = curr -> next;
			curr -> next = pre;
			
			pre = curr;
			curr = nex;	
				}
		x = pre;
		return x;

	}

	
	void searchInsert(struct Node *head, int value){
		struct Node *p = (struct Node*)malloc(sizeof(struct Node));
		struct Node *q = (struct Node*)malloc(sizeof(struct Node));
		
		p -> data = 7;
		q = p;

		while(head -> next != NULL){
			if(head -> data == value){
				q -> next = p;
				p -> next = head;
				break;
			}
			q = head;
			head = head -> next;
		}

	}



	void push(struct Node *head, int value){
		struct Node *p = (struct Node*)malloc(sizeof(struct Node));
		while(head -> next != NULL){
			head = head -> next;
		}

		head->next = p;
		p -> data = value;
		p->next = NULL; 
	}

	void pop(struct Node *head){
		struct Node *p = (struct Node*)malloc(sizeof(struct Node));
		while(head -> next != NULL){
			p = head;
			head = head -> next;
		}

		p -> next = NULL;
	}

	struct Node *head = (struct Node*)malloc(sizeof(struct Node));
	struct Node *two = (struct Node*)malloc(sizeof(struct Node));
	struct Node *three = (struct Node*)malloc(sizeof(struct Node));
	struct Node *four = (struct Node*)malloc(sizeof(struct Node));
	struct Node *five = (struct Node*)malloc(sizeof(struct Node));
	
	head -> data = 1;
	head -> next = two;

	two -> data = 2;
	two -> next = three;

	three -> data = 3;
	three -> next = four;


	four -> data = 4;
	four -> next = five;


	five -> data = 5;
	five -> next = NULL;


	printf("Linked list");

}
