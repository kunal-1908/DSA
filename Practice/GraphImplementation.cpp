#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int>> adjlist;

    void addedge(int u,int v,bool direction){
        //direction-0 undirected
        //direction-1 directed

        adjlist[u].push_back(v);
        if(direction==false){
            adjlist[v].push_back(u);
        }
    }

    void print(){
        for(auto i:adjlist){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};
int main(){
    int edge;
    cout<<"enter the no of edges:"<<endl;
    cin>>edge;

    graph g;
    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;

        g.addedge(u,v,false);
    }

    g.print();
    
    return 0;
}