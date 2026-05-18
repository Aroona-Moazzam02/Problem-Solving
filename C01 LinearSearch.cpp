#include<iostream>
using namespace std;

int main(){
	int csb[10]={55, 20, 10, 25, 87, 22, 45, 76, 90, 12};
	int se, i, index=-1;
	
	cout<<"Enter the Customer ID: ";
	cin>>se;
		
	for(i=0; i<10; i++){
		if(csb[i]== se){
			index = i;
			break;
		}		
	}
	
	if(index == -1){
		cout<<"ID is Not Found"<<endl;		
	}
	else{
		cout<<"ID is Found at index: "<<index<<endl;
	}
	
	return 0;
}
