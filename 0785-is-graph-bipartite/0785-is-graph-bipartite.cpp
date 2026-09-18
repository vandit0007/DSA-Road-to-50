class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0); // 0: uncolored, 1: color A, -1: color B

        for (int i = 0; i < n; ++i) {
            if (color[i] != 0) continue; // Already colored

            // Start BFS from this uncolored node
            queue<int> q;
            q.push(i);
            color[i] = 1; // Assign first color

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : graph[u]) {
                    if (color[v] == 0) {
                        // Assign opposite color
                        color[v] = -color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        // Conflict: adjacent nodes have the same color
                        return false;
                    }
                }
            }
        }

        return true; 
    }
};