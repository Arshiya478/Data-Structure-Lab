// Create CLL with n nodes

		last->next = head->next;
		head = head->next;
		free(curr);

		printf("Deleted element: %d\n", deleted);
		return head;
	}

	for (i = 1; i < pos && curr->next != head; i++) {
	prev = curr;
		curr = curr->next;
	}

	if (i != pos) {
		printf("Position not found\n");
		return head;
	}

	prev->next = curr->next;
	printf("Deleted element: %d\n", curr->data);
	free(curr);

	return head;
}

// Traverse CLL
void traverseListInCLL(NODE head) {

	if(head == NULL)
	{
		printf("CLL is empty\n");
		return;
	}
	NODE temp = head;
	do{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	while(temp != head);
	printf("\n");
}

// Insert at given position in CLL
NODE insertAtPositionInCLL(NODE head, int pos, int data) {
	NODE temp = createNodeInCLL(data);
	if(pos == 1)
	{
		if(head == NULL)
		{
			temp->next = temp;
			return temp;
		}
		else{
			NODE last = head;
			while (last->next != head) last = last->next;
			temp->next = head;
			last->next = temp;
			return temp;
		}
	}

	NODE curr = head;
	int i;
	for(i = 1; i < pos-1 && curr->next != head; i++)
		curr = curr->next;

	if(i != pos-1)
	{
		printf("Position not found\n");
		free(temp);
		return head;
	}

	temp->next = curr->next;
	curr->next = temp;
	return head;
}

// Delete node at given position in CLL
	if (head == NULL) {
		printf("CLL is empty\n");
		return NULL;
	}

	NODE curr = head, prev = NULL;
	int i;

	if (pos == 1) {
		int deleted = head->data;

		if (head->next == head) {
			free(head);
			printf("Deleted element: %d\n", deleted);
			return NULL;
		}

		NODE last = head;
		while (last->next != head)
			last = last->next;

		last->next = head->next;
		head = head->next;
		free(curr);

		printf("Deleted element: %d\n", deleted);
		return head;
	}

	for (i = 1; i < pos && curr->next != head; i++) {
	prev = curr;
		curr = curr->next;
	}

	if (i != pos) {
		printf("Position not found\n");
		return head;
	}

	prev->next = curr->next;
	printf("Deleted element: %d\n", curr->data);
	free(curr);

	return head;
}

// Reverse CLL
NODE reverseCLL(NODE head) {
	if(head == NULL || head->next == head) return head;
	NODE prev = NULL, curr = head, next;
	NODE first = head;

	do {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	} while(curr != head);

	head->next = prev;
	head = prev;
	return head;
}

// Concatenate two CLLs
NODE concatCLL(NODE first, NODE second) {

	if(first == NULL)
		return second;

	if(second == NULL)
		return first;

	NODE last1 = first;
	while(last1->next != first)
		last1 = last1->next;

	NODE last2 = second;
	while(last2->next != second)
		last2 = last2->next;

	last1->next = second;
	last2->next = first;
	return first;
}