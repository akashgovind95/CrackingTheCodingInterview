#include<iostream>
#include<vector>
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
        int fromNode = edge[0];
        int toNode  = edge[1];
        routes[fromNode].push_back(toNode);
    }
    bool isNodeReachable(int node, int toFind){
    
        if(toFind == node)
            return true;
        if(visited[node]==false){
            visited[node]=true;
            for(auto i : routes[node])
                if(visited[i]==false && isNodeReachable(i,toFind))
                    return true;
        }
        visited[node]=false;
        return false;
    }
};

int main(){

    solution case1(4);
    solution case2(5);

    cout<<"Case1:"<<endl;
    case1.addEdge({0,1});
    case1.addEdge({1,2});
    case1.addEdge({2,3});
    case1.addEdge({3,1});

    case1.printGraph();

    cout<<"is 3 reachable from 1? Ans: "<<case1.isNodeReachable(1,3)<<endl;
    cout<<"is 0 reachable from 3? Ans: "<<case1.isNodeReachable(3,0)<<endl;
    cout<<endl;

    cout<<"Case2:"<<endl;
    case2.addEdge({0,1});
    case2.addEdge({1,0});
    case2.addEdge({1,3});
    case2.addEdge({2,0});
    case2.addEdge({2,4});
    case2.addEdge({3,1});
    
    case2.printGraph();
    
    cout<<"is 4 reachable from 3? Ans: "<<case2.isNodeReachable(3,4)<<endl;
    cout<<"is 0 reachable from 3? Ans: "<<case2.isNodeReachable(3,0)<<endl;
    cout<<endl;
    
    return 0;


}