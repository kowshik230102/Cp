#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    Node* insert(Node* root, int value) {
        if (!root) return new Node(value);
        if (value < root->data)
            root->left = insert(root->left, value);
        else if (value > root->data)
            root->right = insert(root->right, value);
        return root;
    }

    Node* findMin(Node* root) {
        while (root->left) root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, int value) {
        if (!root) return root;

        if (value < root->data)
            root->left = deleteNode(root->left, value);
        else if (value > root->data)
            root->right = deleteNode(root->right, value);
        else {
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    void inorder(Node* root) {
        if (root) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void menu() {
        int choice, value;
        while (true) {
            cout << "\n1. Insert\n2. Delete\n3. Exit\nChoose an option: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Enter value to insert: ";
                    cin >> value;
                    root = insert(root, value);
                    cout << "Inorder Traversal: ";
                    inorder(root);
                    cout << endl;
                    break;
                case 2:
                    cout << "Enter value to delete: ";
                    cin >> value;
                    root = deleteNode(root, value);
                    cout << "Inorder Traversal: ";
                    inorder(root);
                    cout << endl;
                    break;
                case 3:
                    return;
                default:
                    cout << "Invalid choice! Try again.\n";
            }
        }
    }
};

int main() {
    BST tree;
    tree.menu();
    return 0;
}
