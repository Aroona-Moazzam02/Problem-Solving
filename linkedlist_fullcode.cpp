#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* adrs;

    Node(int x) { 		//constructor of struct node
        data = x;
        adrs = NULL;	//initially null 
    }
};

class linkedList {
    Node* head;		

public:
    linkedList() {
        head = NULL;
    }

    // Add node at the start
    void addNode_start(int value) {
        Node* newNode = new Node(value); 	//node constructor 
        if (head == NULL) {					//check if any node exist or not , if not exist point it to the head node (starting node)
            head = newNode;
            return;
        }
        newNode->adrs = head;			//if already had a head node so make the newnode as head (putting node at start)
        head = newNode;
    }

    // Add node at the end
    void addNode_last(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->adrs != NULL) {	//checking the last node bcz its adress will be null when we found the last node this will be
            temp = temp->adrs;			//consider as temp and we put newnode here and to link we put newnode 
        }
        temp->adrs = newNode;
    }
    // Search node
    void searchNode(int search_val) {
        if (head == NULL) {
            cout << "List is Empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == search_val) {
                cout << "Searching value " << search_val << " is found" << endl;
                return;
            }
            temp = temp->adrs;
        }
        cout << "Searching value " << search_val << " is not found" << endl;
    }

    // Delete node
    void deleteNode(int del_val) {			
        if (head == NULL) {
            cout << "List is Empty" << endl;
            return;
        }
        if (head->data == del_val) {		//check if the del value is at the head node
            Node* temp = head;
            head = head->adrs;    // head will be the next node and the first head node will be deleted as 
	   				  	 		  //we assign it to the temp and delete it
            delete temp;		 // head node ks deleted
            cout << "Value " << del_val << " is successfully Deleted" << endl;
            return;
        }

        Node* previous = head;		//if the value not match with head then we'll search the other nodes the
        	  		   	 			// so head will be previous and the other node whivh we are checking is current
        Node* current = head->adrs;

        while (current != NULL) {
            if (current->data == del_val) {  //if it will match we have to store the address of next node after it
               				  	 		  	 //in the previous node before deleting the current node
                previous->adrs = current->adrs;  
                delete current;
                cout << "Value " << del_val << " is successfully Deleted" << endl;
                return;
            }							//if not found at that location
            previous = previous->adrs;  		//set the currently chceking node as previous and now check the other
            current = current->adrs;    //other node and set it to the current to  check the other noldes to delete 
        }
        cout << "Value " << del_val << " is not found" << endl;
    }

    // Display list
    void listShow() {
        if (head == NULL) {
            cout << "List is Empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "   ";
            temp = temp->adrs;
        }
        cout << "\n" << endl;
    }

    // Sort ascending
    void sortAscending() {
        if (head == NULL) return;
        Node* i;
        Node* j;
        int temp;
        for (i = head; i->adrs != NULL; i = i->adrs) {
            for (j = i->adrs; j != NULL; j = j->adrs) {
                if (i->data > j->data) {
                    temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }

    // Sort descending
    void sortDescending() {
        if (head == NULL) return;
        Node* i;
        Node* j;
        int temp;
        for (i = head; i->adrs != NULL; i = i->adrs) {
            for (j = i->adrs; j != NULL; j = j->adrs) {
                if (i->data < j->data) {
                    temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }
};

int main() {
    linkedList obj;

    int search_val, del_val;

    // Adding nodes
    obj.addNode_last(64);
    obj.addNode_start(54);
    obj.addNode_last(74);
    obj.addNode_start(44);
    obj.addNode_last(94);
    obj.addNode_start(24);

    cout << "Original List:\n";
    obj.listShow();

    // Search
    cout << "Enter the searching Node value: ";
    cin >> search_val;
    obj.searchNode(search_val);

    // Delete
    cout << "Enter the Node value that you want to Delete: ";
    cin >> del_val;
    obj.deleteNode(del_val);

    cout << "\nList after Deletion:\n";
    obj.listShow();

    // Sorting
    cout << "List Sorted in Ascending Order:\n";
    obj.sortAscending();
    obj.listShow();

    cout << "List Sorted in Descending Order:\n";
    obj.sortDescending();
    obj.listShow();

    return 0;
}

