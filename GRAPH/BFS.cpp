#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

void bfs(vector<vector<int>> &adj, unordered_map<int, bool> &visited,
         vector<int> &ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) { 
        int frontnode = q.front();
        q.pop();

        ans.push_back(frontnode);

        for (auto neighbor : adj[frontnode]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj) {
    vector<int> ans;
    unordered_map<int, bool> visited;

    // Start BFS from vertex 0
    // if (!visited[0]) {
        bfs(adj, visited, ans, 0);
    // }

    return ans;
}
