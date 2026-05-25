#include <iostream>
using namespace std;

class cal{
	private:
		int top;
		int arr[];
	public:
		cal(){
			top = -1;
		}
		
		void D2B(int value){
			while(value>0)
			{  int r=value%2;
			   top++;
			   arr[top]=r;
			   value=value/8;
			}
		}

		
		void print(){
			
			for(int x=top; x>=0; x--){
				cout<<arr[x]<<" ";
			}
			cout<<endl;	
		}	
};

int main() {
	cal a;
	
    a.D2B(45);
	a.print();
	
	a.D2B(67);
	a.print();	

	
	return 0;
}

