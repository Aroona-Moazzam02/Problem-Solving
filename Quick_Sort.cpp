#include<iostream>
using namespace std;

void quickSort(int [], int, int);
int splitting(int [], int, int);

int main(){
	int x, bscs[] = {3, 16, 2, 90, 63, 12, 49, 7, 87};
	
	cout<<"Before Sorting: ";
	for(x=0; x<=8; x++){
		cout<<bscs[x]<<"\t";
	}
	cout<<endl;

	quickSort(bscs, 0, 8);
	
	cout<<"After Sorting: ";
	for(x=0; x<=8; x++){
		cout<<bscs[x]<<"\t";
	}
	cout<<endl;
					
	return 0;
}

void quickSort(int bscs[], int first, int last){	
	
	if(first < last){
		int point = splitting(bscs, first, last);
		
		quickSort(bscs, first, point-1);
		quickSort(bscs, point+1, last);
	}	
}

int splitting(int bscs[], int first, int last){
	int pivot = bscs[first];
	int left = first+1;
	int right = last;
	int temp;
	
	while(1){ // left <= right
		while(bscs[left] <= pivot && left <= right){
			left++;
		}
		while(bscs[right] >= pivot && right >= left){
			right--;
		}
		if(right < left){
			temp = bscs[first];
			bscs[first] = bscs[right];
			bscs[right] = temp;
			break;
		}
		else{
			temp = bscs[left];
			bscs[left] = bscs[right];
			bscs[right] = temp;
			left++;
			right--;			
		}
	}	
	return right;
}
