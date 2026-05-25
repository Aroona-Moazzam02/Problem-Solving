// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct node{
    int data;
    node* adrs;
     node(int x){
         data=x;
         adrs=NULL;
     }
};

class graph{
    int vertices;
    node* head[10];
public:
        graph(int v){
            vertices=v;
            for(int i=0; i<vertices; i++){
                head[i]=NULL;
            }
        }
        
        void add_edges_end(int s, int d){
           node* newnode= new node(d);
           if(head[s]==NULL){
               head[s]=newnode;
               
           }
           else{
               node* temp=head[s];
               while(temp->adrs!= NULL){
                   temp= temp->adrs;
                
               }
               temp->adrs=newnode;
           }
           
           node* newnode2= new node(s);
           if(head[d]==NULL){
               head[d]=newnode2;
              
           }
           else{
               node* temp=head[d];
               while(temp->adrs!= NULL){
                   temp= temp->adrs;
                
               }
               temp->adrs=newnode2;
           }
        }
        
        void add_edge_start(int s, int d){
           
            node* newnode= new node(d);
            newnode->adrs=head[s];
            head[s]=newnode;
            
            node* newnode2= new node(s);
            newnode2->adrs=head[d];
            head[d]=newnode2;
        }
        
         void deletefromlist(int v,int target){
             
             node* temp=head[v];
             node* prevoius=NULL;
             
             if(head[v]==NULL){
                 return;
             }
             
             if(temp->data == target){
                 head[v]=head[v]->adrs;
                delete temp;
                 return;
             }
             
              while(temp!=NULL){
             if(temp->data == target){
                prevoius->adrs=temp->adrs;
             delete temp;
                 return;
             }
               prevoius=temp;
                 temp=temp->adrs;
            
             
             }
       cout<<"No edge found to delete at vertex "<<v<<" for target "<<target<<endl;
            
             
        
             
             
         }
        void delete_node(int s, int d){
            deletefromlist(s,d);
             deletefromlist(d,s);
        }
        
        void display(){
            for(int i=0; i<vertices; i++){
               cout<<"vertix "<<i<<" -> ";
               node* temp=head[i];
               while(temp!=NULL){
                   cout<<temp->data<<" ";
                   temp=temp->adrs;
                   
               }
               cout<<endl;
           } 
        }
        
        
};

int main() {
    graph g(3);
    g.add_edges_end(0,1);
    g.add_edges_end(1,2);
    g.add_edges_end(2,0);
    
    g.display();
    g.delete_node(1,0);
    cout<<"\nafter"<<endl;
    g.display();
    return 0;
}