#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* adrsN ;
	Node* adrsP;
	
	Node(int x){
		data = x;
		adrsN = adrsP= NULL;
	}		
};

class doublelinkedList{
	Node* head;
		
	public:
	doublelinkedList(){
		head = NULL;
	}
	
void addNode_start(int value){
    Node* newNode = new Node(value);

    if(head == NULL){
        head = newNode;
        return;
    }
     head->adrsP = newNode; 
    newNode->adrsN = head;   // new node next → old head
     // old head previous → new node
    head = newNode;          // update head
}

	void addNode_last(int value){		
		Node* newNode = new Node(value);
		if(head == NULL){
			head = newNode;
			return;
		}		
		Node*  temp = head;		
		while(temp->adrsN != NULL){
			temp = temp->adrsN;
		}
		temp->adrsN = newNode;	
		newNode->adrsP=temp;	
	}
	
	
	
	
	void listShow(){
		if(head == NULL){
			cout<<"List is Empty";
			return;
		}	 
		Node* temp = head;
		while(temp != NULL){
			cout<<temp->data<<"   ";
			temp = temp->adrsN;			
		}
		cout<<"\n"<<endl;
		
																					
	}	
	
		void listShowback(){
		if(head == NULL){
			cout<<"List is Empty";
			return;
		}	 
		Node* temp =head;
		
		while(temp->adrsN!= NULL){
			
			temp = temp->adrsN;			
		}
			while(temp != NULL){
			cout<<temp->data<<"   ";
			temp = temp->adrsP;			
		}
		cout<<"\n"<<endl;
		
	}		
	
};

int main(){
	doublelinkedList obj;
    obj.addNode_last(34);
	obj.addNode_last(67);
	obj.addNode_last(89);
	obj.addNode_last(23);
	obj.addNode_last(99);
	obj.addNode_last(12);
	obj.addNode_start(100);
	obj.listShow();
	obj.listShowback();
		
	return 0;
}
