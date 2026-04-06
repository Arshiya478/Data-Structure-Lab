struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertNode(struct TreeNode* root, int data) {
	if (root == NULL)
        return createNode(data);

    if (data < root->val)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);

    return root;
}

void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        printf("The tree is empty");
        return;
    }

    if (root->left)
        inorderTraversal(root->left);

    printf("%d ", root->val);

    if (root->right)
        inorderTraversal(root->right);
}

void preorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        printf("The tree is empty");
        return;
    }
    printf("%d ", root->val);

    if (root->left)
        preorderTraversal(root->left);

    if (root->right)
        preorderTraversal(root->right);
}

void postorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        printf("The tree is empty");
        return;
    }

    if (root->left)
        postorderTraversal(root->left);

    if (root->right)
        postorderTraversal(root->right);

    printf("%d ", root->val);
}
struct TreeNode* findMin(struct TreeNode* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key, int* found) {
	if (root == NULL)
        return NULL;

    if (key < root->val) {
        root->left = deleteNode(root->left, key, found);
    }
    else if (key > root->val) {
        root->right = deleteNode(root->right, key, found);
    }
    else {
        *found = 1;

        // One or no child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Two children
        struct TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val, found);
    }

    return root;
}

// Free tree
void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
