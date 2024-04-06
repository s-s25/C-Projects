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

// Returns an empty list with length 0
LinkedList LinkedList_New(void) {
    LinkedList linkedList = {NULL, 0};
    return linkedList;
}

// Deallocates all nodes of list and sets length to 0
void LinkedList_Free(LinkedList* list) {
    Node* currNode = list->head;
    Node* temp;
    for (int i = 0; i < list->length; i++) {
        temp = currNode->next;
        free(currNode);
        currNode = temp;
    }
    list->length = 0;
}

// Add a node to list which stores value to the end of list
void LinkedList_addToFront(LinkedList* list, int value) {
    Node* newHead = malloc(sizeof(Node));
    newHead->value = value;
    newHead->next = list->head;
    list->head = newHead;
    list->length++;
}

// Add a node to list which stores value to the end of list
void LinkedList_addToEnd(LinkedList* list, int value) {
    Node* newNext = malloc(sizeof(Node));
    newNext->value = value;
    newNext->next = NULL;

    if (list->head == NULL) {
        list->head = newNext;
    } else {
        Node* node = list->head;
        for (int i = 1; i < list->length; i++) {
            node = node->next;
        }
        node->next = newNext;
    }
    list->length++;
}

// Remove the first node of list and return its value
int LinkedList_removeFirst(LinkedList* list) {
    Node* newFirst = list->head->next;
    int value = list->head->value;
    free(list->head);
    list->head = newFirst;
    list->length--;
    return value;
}

// Remove the last node of list and return its value
int LinkedList_removeLast(LinkedList* list) {
    Node* node = list->head;
    for (int i = 2; i < list->length; i++) {
        node = node->next;
    }
    int value = node->next->value;
    free(node->next);
    node->next = NULL;
    list->length--;
    return value;
}

// Return the value of the last element of list
int LinkedList_getLast(LinkedList* list) {
    Node* node = list->head;
    for (int i = 0; i < list->length; i++) {
        node = node->next;
    }
    return node->value;
}

// Return the first element of the list
int LinkedList_getFirst(LinkedList* list) {
    return list->head->value;
}

// Set over the first element of list with value
void LinkedList_setFirst(LinkedList* list, int value) {
    list->head->value = value;
}

// Check if list is empty returns 1 if true 0 if false.
int LinkedList_isEmpty(LinkedList* list) {
    return list->head == NULL;
}

// Print the node count of list
int LinkedList_size(LinkedList* list) {
    return list->length;
}

// Set over the first element of list with value
void LinkedList_setLast(LinkedList* list, int value) {
    Node* node = list->head;
    for (int i = 0; i < list->length; i++) {
        node = node->next;
    }
    node->value = value;
}

// Print all elements of list in order
void LinkedList_print(LinkedList* list) {
    Node* node = list->head;
    for (int i = 0; i < list->length; i++) {
        printf("%d ",node->value);
        node = node->next;
    }
    printf("\n");
}

// Splits off the first node, and appends it at the end of list.
// The function should accomplish this solely by rearranging links: do not allocate new nodes. 
void LinkedList_rotate(LinkedList* list) {
    if (list->length == 1) {
        return;
    }
    
    Node* temp = list->head;
    Node* node = temp->next;
    list->head = node;
    for (int i = 2; i < list->length; i++) {
        node = node->next;
    }
    node->next = temp;
    temp->next = NULL;
}

int main() {
    LinkedList list = LinkedList_New();

    LinkedList_addToEnd(&list, 3);
    LinkedList_addToEnd(&list, 4);
    LinkedList_addToFront(&list, 2);
    LinkedList_addToFront(&list, 1);

    LinkedList_print(&list);

    LinkedList_removeFirst(&list);
    LinkedList_removeLast(&list);

    LinkedList_print(&list);

    LinkedList_rotate(&list);

    LinkedList_print(&list);

    LinkedList_Free(&list);
}