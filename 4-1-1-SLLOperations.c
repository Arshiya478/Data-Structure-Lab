// INSERT

void insert(struct LinkedList* list, int data, int position) {
if (position < 0 || position > list->size) {
    printf("Invalid position\n");
    return;
}

struct Node* newNode = createNode(data);

if (position == 0) {
    newNode->next = list->head;
    list->head = newNode;
} else {
    struct Node* temp = list->head;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

list->size++;
printf("Element %d inserted at position %d\n", data, position);
}



// DELETE

void deleteNode(struct LinkedList* list, int position) {
if (position < 0 || position >= list->size) {
    printf("Invalid position\n");
    return;
}

struct Node* temp;

if (position == 0) {
    temp = list->head;
    list->head = temp->next;
} else {
    struct Node* prev = list->head;
    for (int i = 0; i < position - 1; i++) {
        prev = prev->next;
    }
    temp = prev->next;
    prev->next = temp->next;
}

free(temp);
list->size--;
printf("Element at position %d deleted\n", position);
}



// REVERSE

void reverse(struct LinkedList* list) {
struct Node *prev = NULL, *current = list->head, *next = NULL;

while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
}

list->head = prev;
}
