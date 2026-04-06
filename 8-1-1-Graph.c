#include <stdio.h>
        GNODE del = temp;
        temp = temp->next;
        free(del);
    }

    // Shift graph
    for (int i = v; i < *N; i++) {
        graph[i] = graph[i + 1];
    }
    graph[*N] = NULL;

    (*N)--;

    // Update vertex numbers
    for (int i = 1; i <= *N; i++) {
        GNODE temp2 = graph[i];
        while (temp2 != NULL) {
            if (temp2->vertex > v)
                temp2->vertex--;
            temp2 = temp2->next;
        }
    }

    printf("After deleting vertex the adjacency list is : \n");
    print(N);
}

// Delete Edge
void deleteEdge(int *N) {
    int src, dest;

    printf("Enter the source vertex of the edge : ");
    scanf("%d", &src);
    printf("Enter the destination vertex of the edge : ");
    scanf("%d", &dest);

    if (src < 1 || src > *N || dest < 1 || dest > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    GNODE temp = graph[src], prev = NULL;

    while (temp != NULL) {
        if (temp->vertex == dest) {
            if (prev == NULL)
                graph[src] = temp->next;
            else
                prev->next = temp->next;

            GNODE del = temp;
            temp = temp->next;
            free(del);
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    printf("After deleting edge the adjacency list is : \n");
    print(N);
}