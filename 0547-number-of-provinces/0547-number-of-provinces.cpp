class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[city] = 1;  // Mark current city as visited
        int n = isConnected.size();
        for (int neighbor = 0; neighbor < n; ++neighbor) {
            // If there's a connection and neighbor not visited
            if (isConnected[city][neighbor] == 1 && !visited[neighbor]) {
                dfs(neighbor, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);  // Track visited cities
        int provinceCount = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                // Found a new province
                provinceCount++;
                dfs(i, isConnected, visited);  // Explore all connected cities
            }
        }

        return provinceCount;
    }
};