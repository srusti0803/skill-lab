#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Structure to store the horizontal distance and node data
struct QueueNode {
    struct Node* node;
    int hd; // Horizontal distance
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to print the top view of the binary tree
void topView(struct Node* root) {
    if (root == NULL) return;

    // Create a queue for level order traversal
    struct QueueNode* queue = (struct QueueNode*)malloc(100 * sizeof(struct QueueNode));
    int front = 0, rear = 0;

    // Create a hash map to store the first node at each horizontal distance
    int hashMap[100] = {0}; // Adjust size as needed
    int minHD = 0, maxHD = 0;

    // Enqueue the root node with horizontal distance 0
    queue[rear].node = root;
    queue[rear].hd = 0;
    rear++;

    // Perform level order traversal
    while (front < rear) {
        struct QueueNode current = queue[front++];
        int hd = current.hd;
        struct Node* node = current.node;

        // If this is the first node at this horizontal distance, add it to the hash map
        if (hashMap[hd + 50] == 0) { // +50 to handle negative horizontal distances
            hashMap[hd + 50] = node->data;
            if (hd < minHD) minHD = hd;
            if (hd > maxHD) maxHD = hd;
        }

        // Enqueue the left child with horizontal distance hd-1
        if (node->left != NULL) {
            queue[rear].node = node->left;
            queue[rear].hd = hd - 1;
            rear++;
        }

        // Enqueue the right child with horizontal distance hd+1
        if (node->right != NULL) {
            queue[rear].node = node->right;
            queue[rear].hd = hd + 1;
            rear++;
        }
    }

    // Print the top view nodes from left to right
    for (int i = minHD; i <= maxHD; i++) {
        printf("%d ", hashMap[i + 50]);
    }
    printf("\n");

    free(queue);
}

// Driver code
int main() {
    // Constructing the binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(4);
    root->left->right->right = createNode(5);
    root->left->right->right->right = createNode(6);

    // Print the top view of the binary tree
    printf("Top view of the binary tree is: ");
    topView(root);

    // Free the allocated memory (optional, for completeness)
    free(root->left->right->right->right);
    free(root->left->right->right);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
