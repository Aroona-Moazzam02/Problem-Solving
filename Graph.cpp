#include<iostream>
using namespace std;

struct Node {
    string name;
    Node* adrs;

    Node(string n) {
        name = n;
        adrs = NULL;
    }
};

class Graph {
    int vertices=5;
    Node* head[10];
	string names[5] = {"Alice","Bob","Charlie","David","Eve"};
	public:
    Graph(int v) {
        vertices = v;
        for(int i = 0; i < vertices; i++) {
            Node* newNode = new Node(names[i]);
            head[i] = newNode;
    }
}

	    void addEdge(int s, int d){
        Node* newNode = new Node(head[d]->name);
        Node* temp = head[s];
        while(temp->adrs != NULL){
            temp = temp->adrs;
        }
        temp->adrs = newNode;

        Node* newNode2 = new Node(head[s]->name);
        temp = head[d];
        while(temp->adrs != NULL){
            temp = temp->adrs;
        }
        temp->adrs = newNode2;
    }


    void showGraph() {
        for(int i = 0; i < vertices; i++) {
            cout<<head[i]->name<<" : ";
            Node* temp = head[i]->adrs;
            while(temp != NULL) {
                cout<<temp->name<<" -> ";
                temp = temp->adrs;
            }
            cout<<"NULL"<<endl;
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.showGraph();
    return 0;
}