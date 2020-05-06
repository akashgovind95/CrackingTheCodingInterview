#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class solution{
    public:
    vector<vector<int>> routes;
    vector<int> visited;
    solution(int numOfNodes){
        routes = vector<vector<int>>(numOfNodes);
        visited = vector<int>(numOfNodes);
    }
    void printGraph(){
        for(int i =0;i<routes.size();i++){
            cout<<i<<": ";
            for(auto toNode: routes[i] )
                cout<<toNode<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    void addEdge(vector<int> edge){
        int fromNode = edge[1];
        int toNode  = edge[0];
        routes[fromNode].push_back(toNode);
    }

    void topoUtil(int currNode, stack<int> &s){
        visited[currNode]=1;
        for(auto i : routes[currNode])
            if(visited[i] == 0)
                topoUtil(i,s);
        s.push(currNode);
    }

    void getTopologicalSort(){
        stack<int> s;
        
        for(int i=0;i<routes.size();i++)
            if(visited[i]==0)
                topoUtil(i, s);

        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }

        visited = vector<int>(visited.size(),0);                

    }
    
};

int main(){

    solution case1(6);

    cout<<"Case1:"<<endl;
    case1.addEdge({3,0});
    case1.addEdge({1,5});
    case1.addEdge({3,1});
    case1.addEdge({0,5});
    case1.addEdge({2,3});

    case1.printGraph();
    cout<<endl;
    case1.getTopologicalSort();
    
    cout<<endl;
    
    return 0;


}