#include<iostream>
using namespace std;
int main(){
	int cs[6] = {101, 104, 108, 110, 115, 120};
	int se;
	int mid, first=0, last=5;
	int index = -1;

	cout<<"Enter student roll number to search: ";
	cin>>se;

	while(first < last){
		mid = (first+last)/2;
		
		if(cs[mid] == se)
		{
			index = mid;
			break;
		}
		else if(cs[mid] < se){
			first = mid + 1;
		}
		else{
			last = mid - 1;
		}
	}
	
	if(index == -1)
	{
		cout<<"Student roll number is Not Found"<<endl;
	}
	else{
		cout<<"Student roll number is Found at index: "<<index<<endl;	
	}
			
	return 0;
}
