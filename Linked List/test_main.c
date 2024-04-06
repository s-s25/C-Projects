#include <stdio.h>
#include "linked_list.h" // Assuming linked_list.h contains the function declaration for add_to_end()

int main() {
    // Create a linked list
    LinkedList* list = create_linked_list();

    // Add elements to the end of the list
    add_to_end(list, 10);
    add_to_end(list, 20);
    add_to_end(list, 30);

    // Print the elements of the list
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    // Free the memory allocated for the list
    free_linked_list(list);

    return 0;
}