#include<iostream>
using namespace std;

int main(){
	int arr[5] = {05, 15, 10, 30, 25};
	int i, j, min, temp;
	
	//int *arr = new int[size];
	
	cout<<"Original Values in the Array"<<endl;
	for(i=0; i<5; i++){
		cout<<arr[i]<<"   ";
	}
	
	for(i=0; i<4; i++){
		min = i;
		for(j=i+1; j<5; j++){
			if(arr[j] < arr[min]){
				min = j;
			}		
		}
		
		if(min != i){
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
		
	cout<<"\n\nSorted Values in the Array"<<endl;
	for(i=0; i<5; i++){
		cout<<arr[i]<<"   ";
	}
	
	return 0;
}
