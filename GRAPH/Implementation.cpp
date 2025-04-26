#include <iostream>
#include<list>
#include<unordered_map>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int>> adj;

    void addedges(int u,int v,bool direction){
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printadjlist(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};
int main() {
    // int n;
    // cout<<"enter the no of nodes:"<<endl;
    // cin>>n;
    int m;
    cout<<"enter the no of edges:"<<endl;
    cin>>m;

    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>> u >> v;

        //creating graph
        g.addedges(u,v,0);
    }

    g.printadjlist();
    return 0;
}
