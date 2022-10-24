#include <stdio.h>
#include <stdlib.h>

struct q_node {
    int data;
    struct q_node *next;
};

/* returns new head */
struct q_node *addToQueue(struct q_node *node, struct q_node *head) {
    node->next = head;
    head = node;
    return head;
}

struct q_node *removeFromQueue(struct q_node *tail, struct q_node *head) {
    
    if(tail == head) return NULL;
	
    struct q_node *t;
    struct q_node *prev;
    t = head;
    while(t->next) {
        prev = t;
	t = t->next;
    }
    tail = prev;
    tail->next = NULL;
    free(t);
    return tail;
}


struct q_node *addToQueueEnd(struct q_node *node, struct q_node *tail) {
    tail->next = node;
    return node;
}

struct q_node *createNewNode(int data) {
    struct q_node *new;
    new = (struct q_node*) malloc(sizeof(struct q_node));
    new->data = data;
    new->next = NULL;
    return new;
}

void printList(struct q_node *head) {
    int c = 0;
    printf("------------\n");
    while(head) {
        printf("Queue Item %d:\n    Data: %d\n", c, head->data);
	head = head->next;
	c++;
    }
    printf("------------\n");
    return;
}

int main() {     
    struct q_node *head;
    struct q_node *tail;

    head = addToQueue(createNewNode(7), head);
    tail = head;
    head = addToQueue(createNewNode(2), head);
    printList(head);
    head = addToQueue(createNewNode(4), head);
    tail = addToQueueEnd(createNewNode(9), tail);
    printList(head);
    return 0;
}
