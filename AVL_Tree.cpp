#include<iostream>
using namespace std;

class AVL_Tree {

    struct Node {
        string data;
        Node* left;
        Node* right;
    };

    Node* root;
    public:
        AVL_Tree() {
            root = NULL;
        }

        ~AVL_Tree() {
            delete root;
            root = NULL;
        }

        void insert(string data) {
            root = insert(root, data);
        }

        string search(string data) {
            Node* found = search(root, data);
            if(found != NULL) {
                return (found->data) + " was found";
            }
            return data + " was not found";
        }

    //Functions start here
    Node* search(Node* parent, string data) {
        if(parent == NULL || parent->data == data) {
            return parent;
        }
        
        if((data.compare(parent->data)) < 0) {
            return search(parent->left, data);
        }
        else if ((data.compare(parent->data)) > 0) {
            return search(parent->right, data);
        }
        return parent;
    }

    Node* insert(Node* parent, string data) {
        if(parent == NULL) {
            parent = new Node;
            parent->data = data;
            parent->left = NULL;
            parent->right = NULL;
        }
        else if ((data.compare(parent->data)) < 0) {
            parent->left = insert(parent->left, data);
            parent = balance(parent);
        }
        else if ((data.compare(parent->data)) > 0) {
            parent->right = insert(parent->right, data);
            parent = balance(parent);
        }
        return parent;
    }

    Node* balance(Node* parent) {
        int parentBF = getBalanceFactor(parent);

        //Left-heavy unbalanced tree
        if (parentBF > 1) {
            //Left child node is left-heavy
            if(getBalanceFactor(parent->left) > 0) {
                parent = LL_Rotation(parent);
            }
            //Left child node is right-heavy
            else {
                parent = LR_Rotation(parent);
            }
        }
        //Right-heavy unbalanced tree
        else if (parentBF < -1) {
            //Left child node is left-heavy
            if(getBalanceFactor(parent->right) > 0) {
                parent = RL_Rotation(parent);
            }
            else {
                parent = RR_Rotation(parent);
            }
        }
        return parent;
    }

    int getHeight(Node* parent) {
        int h = 0;
        if (parent == NULL) {
            return -1;
        }
        //Recursively increment everytime there is child
        //and add height of child with tallest height
        h = 1 + max(getHeight(parent->left), getHeight(parent->right));
        return h;
    }

    int getBalanceFactor(Node* parent) {
        return (getHeight(parent->left) - getHeight(parent->right));
    }

    Node* LL_Rotation(Node* parent) {
        Node* temp = parent->left;
        parent->left = temp->right;
        temp->right = parent;
        return temp;
    }

    Node* RR_Rotation(Node* parent) {
        Node* temp = parent->right;
        parent->right = temp->left;
        temp->left = parent;
        return temp;
    }

    Node* LR_Rotation(Node* parent) {
        Node* temp = parent->left;
        parent->left = RR_Rotation(temp);
        return LL_Rotation(parent);
    }

    Node* RL_Rotation(Node* parent) {
        Node* temp = parent->right;
        parent->right = LL_Rotation(temp);
        return RR_Rotation(parent);
    }

};