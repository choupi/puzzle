class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> parent;
    vector<int> vtime;
    vector<int> low;
    int vt;
    vector<vector<int>> res;

    void dfs(int node) {
        //cout << node << endl;
        visited[node] = true;
        vtime[node] = vt++;
        low[node] = vtime[node];
        for (int a: adj[node]) {
            if (!visited[a]) {
                parent[a] = node;
                dfs(a);
                low[node] = min(low[node], low[a]);
            } else if (a != parent[node]) {
                low[node] = min(low[node], vtime[a]);
            }
            if (low[a] > vtime[node]) res.push_back({node, a});
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        visited.resize(n, false);
        parent.resize(n, INT_MAX);
        vtime.resize(n, INT_MAX);
        low.resize(n, INT_MAX);
        vt = 0;
        for (int i=0;i<connections.size();i++) {
            int a = connections[i][0];
            int b = connections[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0);
        return res;
    }
};
