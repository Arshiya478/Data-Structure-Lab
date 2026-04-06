void display() {
	if (head == NULL) {
		printf("List is empty\n");
		return;
	}

	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void insert(int num) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = num;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (head == NULL) {
		head = newNode;
	} else {
		struct Node* temp = head;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = newNode;
		newNode->prev = temp;
	}

	printf("Inserted successfully\n");
}

void deleteNumber(int num) {
	if (head == NULL) {
		printf("List is empty\n");
		return;
	}

	struct Node* temp = head;

	while (temp != NULL && temp->data != num)
		temp = temp->next;

	if (temp == NULL) {
		printf("Number %d not found\n", num);
		return;
	}

	if (temp == head) {
		head = head->next;
		if (head != NULL)
			head->prev = NULL;
	} 
	else {
		temp->prev->next = temp->next;
		if (temp->next != NULL)
			temp->next->prev = temp->prev;
	}

	free(temp);

	printf("List after deletion: ");
	display();
}

void reverseList() {
	 if (head == NULL) {
		printf("List is empty\n");
		return;
	}

	struct Node* temp = NULL;
	struct Node* curr = head;

	while (curr != NULL) {
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = curr->prev;
	}

	if (temp != NULL)
		head = temp->prev;

	display();
}

void concatenate() {
	int n;
	scanf("%d", &n);

	if (n == 0) {
		printf("Second list is empty\n");
		return;
	}

	struct Node* second = NULL;
	struct Node* last2 = NULL;

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);

		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = x;
		newNode->next = NULL;
		newNode->prev = NULL;

		if (second == NULL) {
			second = newNode;
			last2 = newNode;
		} else {
			last2->next = newNode;
			newNode->prev = last2;
			last2 = newNode;
		}
	}

	if (head == NULL) {
		head = second;
		display();
		return;
	}

	struct Node* temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = second;
	second->prev = temp;

	display();
}