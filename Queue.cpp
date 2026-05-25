#include<iostream>
using namespace std;
#define size 5
int queue[size];
int front= -1;
int rear= -1;

     void enqueue(int value){
     	if(rear== size-1){
     		cout<<"Queue is empty"<<endl;
		 }
		else{
			if(front== -1){
				front=0;
			}
			rear++;
			queue[rear] =value;
			cout<<"Marks of "<<rear+1<<" student added:"<<value<<endl;
		} 
}
     void dequeue(){
        if (front== -1 || front > rear){
        	cout<<"Queue is empty"<<endl;
		}
		else{
			cout<<endl;
			cout<<front+1<<" student marks "<<queue[front]<<" removed from queue ";
			front++;
		}
}
        void display(){
		if(front== -1 || front>rear){
			cout<<"Queue is empty"<<endl;
		}
		
		else{
			cout<<"\nstudents marks: ";
			for(int i=front; i<=rear ; i++){
				cout<<queue[i]<<" ";
			}
			cout<<endl;
		}
		}
int main(){
	 enqueue(65);
	  enqueue(36);
	  enqueue(94);
	  enqueue(88);
	  enqueue(59);
		display();
	  dequeue();
	  dequeue();
	display();
	
return 0;	
}