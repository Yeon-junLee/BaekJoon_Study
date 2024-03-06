#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;

    Node* leftChild;
    Node* rightChild;
};

class BST {
private :
    Node* root;
public:
    BST() {
        root = nullptr;
    }
    void insert(int elem);
    Node* getRoot();
    void postorder(Node* node);
};

void BST::insert(int elem) {
    Node* temp = new Node;
    if(root == nullptr) {
        temp->data = elem;
        temp->leftChild = nullptr;
        temp->rightChild = nullptr;
        root = temp;
        return;
    }
    Node* cur = root;
    while(1) {
        while(cur->data > elem) {
            if(cur->leftChild == nullptr) {
                temp->data = elem;
                temp->leftChild = nullptr;
                temp->rightChild = nullptr;
                cur->leftChild = temp;
                return;
            }
            else {
                cur = cur->leftChild;
            }
        }
        while(cur->data < elem) {
            if(cur->rightChild == nullptr) {
                temp->data = elem;
                temp->leftChild = nullptr;
                temp->rightChild = nullptr;
                cur->rightChild = temp;
                return;
            }
            else {
                cur = cur->rightChild;
            }
        }
    }
}

void BST::postorder(Node* node) {
    if(node->leftChild != nullptr)  postorder(node->leftChild);
    if(node->rightChild != nullptr) postorder(node->rightChild);
    cout << node->data << "\n";
}

Node* BST::getRoot() {
    return root;
}


int main() {
    BST* bst = new BST();
    while(1) {
        int n;
        cin >> n;
        if(cin.eof())   break;
        bst->insert(n);
    }

    Node* root = bst->getRoot();
    bst->postorder(root);

    return 0;
}