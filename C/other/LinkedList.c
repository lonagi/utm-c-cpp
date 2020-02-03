#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
    int data;
    struct LinkedList* next;
};

typedef struct LinkedList *Node;

Node createNode(void);
Node append(Node head, int value);
Node prepend(Node head, int value);
Node insert(Node head, int value, int index);
Node insertOrdered(Node head, int value);
Node removeNode(Node head, int value);
Node insertionSort(Node head);
Node reverseList(Node head);
Node swapNodes(Node head, int idxFirst, int idxSecond);

int editNode(Node head, int newValue, int index);
int findNode(Node head, int value);
int countNodes(Node head);
int getAddress(Node head);

void printList(Node head);

int main(int argc, const char * argv[]) {
    
	Node head = NULL;
	
	head = append(head, 6);
	head = append(head, 5);
	head = append(head, 3);
	head = append(head, 1);
	head = append(head, 7);
	
	int count = countNodes(head);

	editNode(head, 8, 0);
	printf("hello");

	head = swapNodes(head, 0, 4);

	printList(head);

	getAddress(head);

	printf("hello");
	
  return 0;
}

Node createNode(void) {
  Node temp;
  temp = malloc(sizeof(Node));
  temp->next = NULL;
  return temp;
}

Node append(Node head, int value) {
    
	Node newNode, currNode;
	
	newNode = createNode();
	newNode -> data = value;
	
	if (head == NULL) {
			head = newNode;
	} 
	else {
		currNode = head;
		while (currNode -> next) {
			currNode = currNode -> next;
		}
		currNode -> next = newNode;
	}
	
  return head;
}

void printList(Node head) {
    
  Node currNode = head;
    
  while (currNode) {
		if (currNode -> next) {
			printf("%2d ->", currNode -> data);
		} 
		else {
			printf("%2d \n", currNode -> data);
		}

    currNode = currNode -> next;
  }
    
}

Node prepend(Node head, int value) {
    
	Node newNode;
	
	newNode = createNode();
	newNode -> data = value;
	
	if (head == NULL) {
		head = newNode;
	} 
	else {
		newNode -> next = head;
		head = newNode;
	}
	
  return head;
}

Node insert(Node head, int value, int index) {
            
  Node newNode = createNode();
  newNode -> data = value;

	if (head == NULL) {
			head = newNode;
			return head;
	}
			
	Node currNode, prevNode;
	currNode = head;
	prevNode = NULL;

	int currPos = 0;
			
	while (currNode) {
		if (index < currPos++) { 
			if (prevNode) {
				prevNode -> next = newNode;
				newNode -> next = currNode;
				break;
			} 
			else {
				head = newNode;
				head -> next = currNode;
				break;
			}
		} else {
			if (currNode -> next) {
				prevNode = currNode;
				currNode = currNode -> next;
			} 
			else {
				currNode -> next = newNode;
				break;
			}
		}
	}
	
  return head;
}

Node insertOrdered(Node head, int value) {
    
	Node newNode = createNode();
	newNode -> data = value;
	
	if (head == NULL) {
		head = newNode;
		return head;
	}
			
	Node currNode, prevNode;
	currNode = head;
	prevNode = NULL;
	
	int comparison;
			
	while (currNode) {
			
		comparison = (newNode -> data) > (currNode -> data) ? 1 : -1;
		
		if (comparison > 0) {
			
			if (currNode -> next) {
				prevNode = currNode;
				currNode = currNode -> next;
			} 
			else {
				currNode -> next = newNode;
				break;
			}
		} 
		else {
			if (prevNode) {
				prevNode -> next = newNode;
				newNode -> next = currNode;
				break;
			} 
			else {
				head = newNode;
				head -> next = currNode;
				break;
			}
		}
	}	
	
	return head;
}

Node reverseList(Node head) {
    
	if (head == NULL) {
			return head;
	}
	
	printf("reversing a list \n");
			
	Node currNode, prevNode, nextNode;
	currNode = head;
	prevNode = NULL;
	nextNode = NULL;
	
	while (currNode) {
		nextNode = currNode -> next;
		currNode -> next = prevNode;
		prevNode = currNode;
		currNode = nextNode;
	}
					
	head = prevNode;
			
	return head;
}

Node removeNode(Node head, int value) {
 
	Node currNode, prevNode;
	currNode = head;
	prevNode = NULL;
	
	while (currNode) {
			
		if (currNode -> data == value) {
			if (currNode == head) {
				currNode = currNode -> next;
				head = currNode;
				break;
			} 
			else {
				prevNode -> next = currNode -> next;
				break;
			}
		} else if (currNode -> data != value) {
				prevNode = currNode;
				currNode = currNode -> next;
		}
	}
	
  return head;
}

// mark first element as sorted
// then make shift and insert each
// element one by one
Node insertionSort(Node head) {
    
	if (head == NULL) {
		printf("nothing to sort \n");
		return head;
	}

	printf("sorting \n");
		
	Node x, y, e;
	
	x = head;
	head = NULL;
	
	while (x != NULL) {
			
		e = x;
		x = x -> next;
		
		if (head != NULL) {
			if (e -> data > head -> data) {
				y = head;
				while ((y -> next != NULL) && (e -> data > y -> next -> data)) {
					y = y -> next;
				}
				
				e -> next = y -> next;
				y -> next = e;		
			} 
			else {
				e -> next = head;
				head = e;
			}
		} else {
			e -> next = NULL;
			head = e;
		}

	}

  return head;
}

int findNode(Node head, int value) {

	if (head == NULL) {
		printf("the list is empty \n");
		return -1;
	}

	Node currNode = head;

	while (currNode) {
		
		if ((currNode -> data) == value) {
			printf("found the node \n");
			return 0;
		}

		currNode = currNode -> next;
	}

	printf("node was not found \n");
	return 1;
}

int countNodes(Node head) {

	Node currNode = head;

	int i = 0;

	for (i = 0; currNode != NULL; i++, currNode = currNode -> next);
	
	printf("length of the list is %d \n", i);
	return i; 
}

Node swapNodes(Node head, int idxFirst, int idxSecond) {

	if ((idxFirst < 0) || (idxSecond < 0)) {
		printf("invalid indicies");
		return head;
	}

	Node currNode, firstNode = NULL, secondNode = NULL, prevFirst = NULL, prevSecond = NULL, temp;

	currNode = head;
	int i = 0;

	if (idxFirst == idxSecond) {
		return head;
	}

	while (currNode) {
		
		if (i == (idxFirst - 1)) {
			prevFirst = currNode;
		} else if (i == idxFirst) {
			firstNode = currNode;
		}
		
		if (i == (idxSecond - 1)) {
			prevSecond = currNode;
		} else if (i == idxSecond) {
			secondNode = currNode;
		}

		if (firstNode && secondNode) {
			break;
		}

		i++;
		currNode = currNode -> next;
	} 

	if (firstNode && secondNode) {

		printf("swapping node %d with node %d \n", firstNode -> data, secondNode -> data);

		if (prevFirst) {
			prevFirst -> next = secondNode;
		} else {
			head = secondNode;
		}

		if (prevSecond) {
			prevSecond -> next = firstNode;
		} else {
			head = firstNode;
		}
	
		temp = firstNode -> next;
		firstNode -> next = secondNode -> next;
		secondNode -> next = temp;
	} else {
		printf("one of the indicies was not found \n");
	}

	return head;
}

int editNode(Node head, int newValue, int index) {

	if (index < 0) {
		printf("invalid index \n");
		return -1;
	}
	
	Node currNode, prevNode = NULL;

	currNode = head;

	int i = 0;
	int value;

	int flag = 1;

	while (currNode) {
		if (i == index) {
			currNode -> data = newValue;
			flag = 0;
			break;
		}

		i++;
		currNode = currNode -> next;
	}

	if (flag) {
		printf("index is out of range \n");
		return -1;
	}

	return 0;
}

int getAddress(Node head) {

	if (head == NULL) {
		return -1;
	}

	Node currNode = head;
	
	while (currNode -> next) {
		currNode = currNode -> next;
	}

	printf("last element is %d with address %p", currNode -> data, &currNode);
	return 0;
}
