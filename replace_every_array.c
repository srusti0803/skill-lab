#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new BST node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Function to find the smallest element greater than the given value
int findSmallestGreater(struct TreeNode* root, int val) {
    int result = -1;
    while (root != NULL) {
        if (root->val > val) {
            result = root->val;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return result;
}

// Function to replace each element with the smallest greater element on its right
void replaceWithSmallestGreater(int arr[], int n) {
    if (n == 0) return;

    // Initialize the BST with the last element
    struct TreeNode* root = createNode(arr[n - 1]);
    arr[n - 1] = -1; // Last element has no elements to its right

    // Traverse the array from right to left
    for (int i = n - 2; i >= 0; i--) {
        // Find the smallest greater element in the BST
        int smallestGreater = findSmallestGreater(root, arr[i]);
        // Insert the current element into the BST
        root = insert(root, arr[i]);
        // Replace the current element with the smallest greater element
        arr[i] = smallestGreater;
    }
}

// Main function
int main() {
    int arr[] = {6, 2, 8, 1, 4, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    replaceWithSmallestGreater(arr, n);

    // Print the modified array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
