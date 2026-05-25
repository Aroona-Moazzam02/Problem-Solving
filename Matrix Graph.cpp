#include<iostream>
using namespace std;

class graph{
	float adjmax[5][5];
	
	public:
		
		void create_matrix(){
			
			for(int r=0; r<=5; r++){
				for(int c=0; c<=5 ;c++){
				  adjmax[r][c]=0;
				  cout<<adjmax[r][c]<<"  ";
				}
				cout<<"\n";
			}
			cout<<"\n";
		}
		
		void add_edge(int x, int y, float w){
		       if((x>=0 && x<5) && (y>=0 && y<5))
			{
			adjmax[x][y]=w;
			}
			
		}
		
		void showmatrix(){
			for (int r=0; r<5; r++){
				for (int c=0; c<5; c++){
				cout<<adjmax[r][c]<<"\t";
					
				}
				cout<<"\n";
			}
		}
};
int main(){
	graph g;
	float weight;
		g. create_matrix();
	
		cout<<"Enter Weight of SAHIWAL fuel cost :";
		     cin>>weight;
		g.add_edge(1,1,weight);
		cout<<"Enter Weight of MULTAN fuel cost:";
	      	cin>>weight;
		g.add_edge(0,4,weight);
		cout<<"Enter  Weight of LAHORE fuel cost:";
			cin>>weight;
		g.add_edge(2,2,weight);
		g.showmatrix();
		
		
	return 0;
}


