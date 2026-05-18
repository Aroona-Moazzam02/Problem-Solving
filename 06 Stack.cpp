#include <iostream>
using namespace std;

class bscs{
	private:
		int top;
		int arr[10];
	public:
		bscs(){
			top = -1;
		}
		
		void push(int value){
			top++;
			arr[top] = value;
		}
	
		void pop(){
			int val = arr[top];
			arr[top] = NULL;						
			cout<<"Value "<<val<<" is Pop"<<endl;
			//top--;
			
			cout<<"Deleted valuie is present or Not: "<<arr[2]<<endl;
		}
		
		void print(){
			if(top == -1){
				cout<<"Stack is Empty"<<endl;				
				return;
			}			
			for(int x=top; x>=0; x--){
				cout<<arr[x]<<endl;
			}	
		}	
};

int main() {
	bscs a;
	
	a.push(45);
	a.push(20);
	a.push(15);
	a.print();	
	a.pop();	
	//a.print();
	
	/*
	a.push(10);
	a.push(30);
	a.push(21);
	a.print();
	a.pop();
	a.pop();
	a.print();
	a.push(50);
	a.push(40);
	a.push(32);
	a.print();
	*/
	
	return 0;
}

