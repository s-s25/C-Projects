#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct LinkedList {
	Node* head;
	int length;
} LinkedList;

LinkedList LinkedList_New(void) {
    LinkedList linkedList = {NULL, 0};
    return linkedList;
}

void LinkedList_Free(LinkedList * list) {
    Node* currNode = (*list).head;
    Node* nextNode = (*currNode).next;
    while (nextNode != NULL) {
        free(currNode);
        currNode = nextNode;
        nextNode = (*currNode).next;
    }
    free(list);
}

void LinkedList_addToFront(LinkedList * list, int value) {
    Node* newHead = malloc(sizeof(Node));
    (*newHead).value = value;
    (*newHead).next = (*list).head;
    (*list).head = newHead;
}

void LinkedList_addToEnd(LinkedList * list, int value) {
    Node node = *(*list).head;
    while (node.next != NULL) {
        node = *(node.next);
    }
    Node* newNext = malloc(sizeof(Node));
    (*newNext).value = value;
    (*newNext).next = NULL;
    node.next = newNext;
}

int LinkedList_removeFirst(LinkedList * list) {
    Node* newFirst = (*(*list).head).next;
    int value = (*(*list).head).value;
    free((*list).head);
    (*list).head = newFirst;
    (*list).length--;
    return value;
}

int LinkedList_removeLast(LinkedList * list) {
    Node* node = (*list).head;
    while ((*(*node).next).next != NULL) {
        node = (*node).next;
    }
    int value = (*(*node).next).value;
    free((*node).next);
    (*node).next = NULL;
    return value;
}

int LinkedList_getLast(LinkedList * list) {
    Node node = *(*list).head;
    while (node.next != NULL) {
        node = *(node.next);
    }
    return node.value;
}

int LinkedList_getFirst(LinkedList * list) {
    return (*(*list).head).value;
}

void LinkedList_setFirst(LinkedList * list, int value) {
    (*(*list).head).value = value;
}

int LinkedList_isEmpty(LinkedList * list) {
    return (*list).head == NULL;
}

int LinkedList_size(LinkedList * list) {
    return (*list).length;
}

void LinkedList_print(LinkedList * list) {
    Node node = *(*list).head;
    while (node.next != NULL) {
        printf("%d ",node.value);
        node = *(node.next);
    }
    printf("\n");
}

void LinkedList_setLast(LinkedList * list, int value) {
    Node node = *(*list).head;
    while (node.next != NULL) {
        node = *(node.next);
    }
    node.value = value;
}