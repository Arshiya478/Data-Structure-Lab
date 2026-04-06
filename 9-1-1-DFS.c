// Function to create a new adjacency list node
Node* createNode(int vertex) {
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
    
}

// Function to add an edge to the graph
void addEdge(int u, int v) {
    
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
    
}

// Function to sort the adjacency list for each vertex
void sortAdjList(int V) {
    
    for(int i = 0; i < V; i++) {
        if (adjList[i] == NULL) continue;

        Node *sorted = NULL;

        Node *current = adjList[i];
        while (current != NULL) {
            Node *next = current->next;

            if (sorted == NULL || current->vertex < sorted->vertex) {
                current->next = sorted;
                sorted = current;
            } else {
                Node *temp = sorted;
                while (temp->next != NULL && temp->next->vertex < current->vertex) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }

            current = next;
        }

        adjList[i] = sorted;
    }
    
}

// Depth-First Search (DFS) function
void DFS(int start) {
    
    visited[start] = 1;
    printf("%d ", start);

    Node* temp = adjList[start];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
    }
    
}