class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return;
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        const int INF = 2147483647; // Represents empty land
        
        // Step 1: Find all treasures and add them to our BFS queue
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        // Directions for moving: down, up, right, left
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // Step 2: Perform Multi-Source BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;
                
                // Step 3: Check bounds and if the neighbor is an unvisited empty land cell
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == INF) {
                    // Update the distance for the empty land
                    grid[nr][nc] = grid[r][c] + 1;
                    // Push the newly updated cell into the queue to explore its neighbors
                    q.push({nr, nc});
                }
            }
        }
        
    }
};
