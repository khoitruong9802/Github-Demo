#include <iostream>

using namespace std;

//AVL tree
class AVLTree
{
public:
    struct Node
    {
        int data;
        Node* left;
        Node* right;
        int height;
    };
    Node* root;
    AVLTree()
    {
        root = NULL;
    }
    void insert(int data)
    {
        root = insert(root, data);
    }
    Node* insert(Node* node, int data)
    {
        if (node == NULL)
        {
            Node* temp = new Node;
            temp->data = data;
            temp->left = NULL;
            temp->right = NULL;
            temp->height = 1;
            return temp;
        }
        if (data < node->data)
        {
            node->left = insert(node->left, data);
            if (height(node->left) - height(node->right) == 2)
            {
                if (data < node->left->data)
                    node = leftRotate(node);
                else
                    node = leftRightRotate(node);
            }
        }
        else
        {
            node->right = insert(node->right, data);
            if (height(node->right) - height(node->left) == 2)
            {
                if (data > node->right->data)
                    node = rightRotate(node);
                else
                    node = rightLeftRotate(node);
            }
        }
        node->height = max(height(node->left), height(node->right)) + 1;
        return node;
    }
    int height(Node* node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }
    Node* rightRotate(Node* node)
    {
        Node* temp = node->left;
        node->left = temp->right;
        temp->right = node;
        node->height = max(height(node->left), height(node->right)) + 1;
        temp->height = max(height(temp->left), node->height) + 1;
        return temp;
    }
    Node* leftRotate(Node* node)
    {
        Node* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        node->height = max(height(node->left), height(node->right)) + 1;
        temp->height = max(height(temp->right), node->height) + 1;
        return temp;
    }
    Node* rightLeftRotate(Node* node)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    Node* leftRightRotate(Node* node)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    void inorder(Node* node)
    {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main() {
    //code
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.inorder(tree.root);
    return 0;
}