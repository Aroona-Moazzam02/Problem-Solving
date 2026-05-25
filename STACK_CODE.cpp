# include <iostream>
using namespace std;
class stack
{ private:
	int top;
	char name[20] ;
public:
	
stack()
{  top=-1;
}

void push(char value[]){
    if(top==20){
        cout<<"Stack is overflow"<<endl;
  }
 else{
  
  for(int i=0; name[top]!='\0'; i++)
  {
  	top++;
  name[top]=value[i];
  }
  }
  }
  
void display(){
   
     cout<<"\nReverse name:";
      for(int i=top; i>=0; i--){
           cout<<name[i];
}
}
};
int main()
{ stack s;
  char n[20];
  cout<<"Enter your name:";
  cin>>n;
  s.push(n);
  s.display();

return 0;
}