#include <stdio.h>
#include <stdlib.h> 

struct Node;
void add_value(struct Node *root, int value);
void remove_value(struct Node *root, int value);
void print_list(struct Node *root);

struct Node{
	int value;
	struct Node *next;
};

int main(void){
	struct Node* root = malloc(1 * sizeof(struct Node));
	root->value = 0;
	root->next = 0;

	printf("\nWelcome to Linked List!\nCommands: add number: a <int> | delete number: d <int> | print list: p 1\n");

	while(1){
		char command = '\0';
	    int value = 0;
		printf("Enter command (a <int> | d <int> | p 1): ");
	    scanf(" %c %d",&command,&value);
	    if(command == 'a'){
		    add_value(root, value);
	    	printf("Added %d \n",value);
	    }else if(command == 'd'){
			remove_value(root, value);
			printf("Removed %d \n",value);
	    }else if(command == 'p'){
			print_list(root);
	    }

	}

	return 0;
}


void add_value(struct Node *root, int value){
	// if end, add value, else, continue
	if (! root->next){
		struct Node* next = malloc(1 * sizeof(struct Node));
		root->next = next;
		next->value = value;
		next->next = 0;
		return;
	}else{
		add_value(root->next,value);
	}
}


void remove_value(struct Node *root, int value){
	// return if final 
	if(! root->next){
		return;
	}

	struct Node* next = root->next; 
	// if next and value, remove and keep root for next
	if(root->next && (value == root->next->value)){
		root->next = root->next->next;
		next = root;
	}

	// continue
	remove_value(next, value);
}

void print_list(struct Node *root){
	printf("Node: %i \n", root->value);
	if (! root->next){
		return;
	}else{
		print_list(root->next);
	}
}