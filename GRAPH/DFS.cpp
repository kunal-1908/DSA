#include<unordered_map>
void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adjlist,
vector<int> &component){
    component.push_back(node);
    visited[node]=true;

    for(auto i:adjlist[node]){
        if(!visited[i]){
            dfs(i,visited,adjlist,component);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int,list<int>> adjlist;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int,bool> visited;

    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,visited,adjlist,component);
            ans.push_back(component);
        }
    }
    return ans;
}