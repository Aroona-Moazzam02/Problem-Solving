#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    Node* head;
    BST() { head = NULL; }

    void insert(int value){
        Node* newnode = new Node(value);    
        if(head == NULL){
            head = newnode;
            return;
        }    
        Node* temp = head;
        Node* parent = NULL;
        while(temp != NULL){
            parent = temp;
            if(temp->data == value){
                cout<<"Same value cannot be added."<<endl;
                return;
            }
            if(temp->data > value)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if(value < parent->data)
            parent->left = newnode;
        else
            parent->right = newnode;
    }

    void in_order(Node* root){
        if(root == NULL) return;
        in_order(root->left);
        cout << root->data << " ";
        in_order(root->right);
    }

  Node* deleteNode(Node* root, int val) {
    if (root == NULL) return NULL; // tree empty

    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else {
        // 1️ Leaf node
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }

        // 2⃣ Node with 1 child
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // 3️ Node with 2 children
        Node* temp = root->right;
        while (temp->left) 
        temp = temp->left; // find inorder successor
        root->data = temp->data;              // replace
        root->right = deleteNode(root->right, temp->data); // delete duplicate
    }
    return root;
}

     // BST ke head se delete call karne ke liye
    void deleteValue(int val) {
    head = deleteNode(head, val);
}

};

int main(){
    BST b;
    b.insert(50);
    b.insert(20);
    b.insert(30);
    b.insert(40);
    b.insert(70);
    b.insert(60);
    b.insert(80);

    cout << "In-order before deletion: ";
    b.in_order(b.head);
    cout << endl;

    b.deleteValue(40);
     b.deleteValue(50);
    cout << "In-order after deletion: ";
    b.in_order(b.head);
    cout << endl;


    return 0;
}