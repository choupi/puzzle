class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        unordered_set<int> unvisit;
        vector<int> nodes(graph.size(), 0);
        for (int i=0;i<graph.size();i++) {
            unvisit.insert(i);
        }
        while (unvisit.size()>0) {
            auto it = unvisit.begin();
            int n = *it;
            nodes[n] = 1;
            q.push(n);
            unvisit.erase(n);
            while (q.size()>0) {
                n = q.front();
                q.pop();
                for (int nn: graph[n]) {
                    if (nodes[nn]==0) {
                        nodes[nn] = -1*nodes[n];
                        q.push(nn);
                        unvisit.erase(nn);
                    } else if (nodes[nn]*nodes[n]!=-1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
