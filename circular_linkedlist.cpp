#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* adrs;
		
		Node(int x){
			data = x;
			adrs = NULL;
		}
};

class Circular_LinkedList{
	Node* head;	
	
	public:
		Circular_LinkedList(){
			head = NULL;			
		}
		
		// Insert_Value 
		void insertData(int x){
			Node* newNode = new Node(x);			
			if(head == NULL){
				head = newNode;
				newNode->adrs = head;
				return;
			}			
			
			Node* temp = head;
									
			while(temp->adrs != head){
				temp = temp->adrs;				
			}				
			temp->adrs = newNode;
			newNode->adrs = head;
		}		

	// Add node at the start (Circular Singly Linked List)
void addNode_start(int value) {
    Node* newNode = new Node(value);   // node constructor

    // If list is empty
    if (head == NULL) {
        head = newNode;
        newNode->adrs = head;          // point to itself
        return;
    }

    // Find last node
    Node* temp = head;
    while (temp->adrs != head) {
        temp = temp->adrs;
    }

    newNode->adrs = head;  // new node points to old head
    temp->adrs = newNode;  // last node points to new head
    head = newNode;        // update head
}

		// Print_List
		void printData(){
			if(head == NULL){
				cout<<"list is empty"<<endl;
				return;
			}
			
			Node* temp = head;					
			
			do{					
				cout<<temp->data<<"   ";
				temp = temp->adrs;				
			}while(temp != head);
				
			cout<<endl;				
		}		
						
		// Serach_Value
		void searchData(int s){
			if(head == NULL){
				cout<<"List is Empty, So you can not search any Data"<<endl;
				return;
			}			
			Node* temp = head;
			
			do{
				if(temp->data == s){
					cout<<"Data "<<s<<" is found in the list"<<endl;
					return;
				}
				temp = temp->adrs;														
			}while(temp != head);
			cout<<"Data "<<s<<" is not found in the List"<<endl;					
		}	
		
		// Delete_Value
		void del(int a) {
    if (head == NULL) {
        cout << "The list is empty" << endl;
        return;
    }

    Node* temp = head;
    Node* p = NULL;

    // Case 1: Only one node
    if (head->data == a && head->adrs == head) {
        delete head;
        head = NULL;
        return;
    }

    // Case 2: Delete head node
    if (head->data == a) {
        // find last node
        Node* last = head;
        while (last->adrs != head) {
            last = last->adrs;
        }

        head = head->adrs;
        last->adrs = head;
        delete temp;
        return;
    }

    // Case 3: Delete middle or last node
    p = head;
    temp = head->adrs;

    while (temp != head) {
        if (temp->data == a) {
            p->adrs = temp->adrs;
            delete temp;
            return;
        }
        p = temp;
        temp = temp->adrs;
    }

    cout << "Value not found" << endl;
}

};

int main(){
	Circular_LinkedList list;
	int insert_val, search_val, delete_val;
	
	for(int i=1; i<=3; i++){
		cout<<"Enter the value of Node is ";	
		cin>>insert_val;
		list.insertData(insert_val);
	}
	
	cout<<"\nThese values are in the List:"<<endl;
	list.printData();
		
	cout<<"\nEnter the value that you want to Search: "<<endl;
	cin>>search_val;
	list.searchData(search_val);
	
	cout<<"\nEnter the value that u want to Delete: "<<endl;
	cin>>delete_val;
	list.del(delete_val);
	
	cout<<"\nThese values are in the List after Deletion: "<<endl;
	list.printData();
	
	return 0;
}
