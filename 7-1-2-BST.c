Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}


Node* insert(Node *root, int data) {
	if (root == NULL)
		return createNode(data);

	if (data < root->data)
		root->left = insert(root->left, data);
	else if (data > root->data)
		root->right = insert(root->right, data);

	return root;
}

Node* findMin(Node *root) {
	while (root && root->left != NULL)
		root = root->left;
	return root;
}


Node* deleteNode(Node *root, int key) {
	if (root == NULL)
		return root;

	if (key < root->data)
		root->left = deleteNode(root->left, key);
	else if (key > root->data)
		root->right = deleteNode(root->right, key);
	else {

		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		}

		else if (root->left == NULL) {
			Node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			Node *temp = root->left;
			free(root);
			return temp;
		}

		Node *temp = findMin(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}

bool search(Node *root, int key) {
	if (root == NULL)
		return false;

	if (key == root->data)
		return true;
	else if (key < root->data)
		return search(root->left, key);
	else
		return search(root->right, key);
}