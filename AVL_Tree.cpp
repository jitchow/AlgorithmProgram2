#include<iostream>
using namespace std;

class AVL_Tree {

    struct Node {
        string data;
        Node* left;
        Node* right;
    };

    Node* root;
    int sum = 0;
    public:
        AVL_Tree() {
            root = NULL;
        }

        ~AVL_Tree() {
            cout << root->data << " is data" << endl;
            cout << root->left->data << " is left" << endl;
            cout << root->right->data << " is right" << endl;
            
        }

        void insert(string data) {
            root = insert(root, data);
        }

    //Functions start here
    Node* insert(Node* root, string data) {
        if(root == NULL) {
            root = new Node;
            root->data = data;
            root->left = NULL;
            root->right = NULL;
        }
        else if ((data.compare(root->data)) < 0) {
            root->left = insert(root->left, data);
        }
        else if ((data.compare(root->data)) > 0) {
            root->right = insert(root->right, data);
        }
        return root;
    }
};

