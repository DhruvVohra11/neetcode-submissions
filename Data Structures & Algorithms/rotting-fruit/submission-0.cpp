class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int freshCount = 0;

        // Step 1: Push all rotten oranges to the queue AND count fresh oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        // If there are no fresh oranges to begin with, it takes 0 minutes
        if (freshCount == 0) return 0;

        int time = 0;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Step 2: Perform Multi-Source BFS level-by-level
        while (!q.empty() && freshCount > 0) {
            int levelSize = q.size(); // Number of oranges rotting at the current minute
            
            for (int i = 0; i < levelSize; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto dir : directions) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    // If we find a fresh orange, rot it
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; // Mark as rotten to avoid revisiting
                        freshCount--;     // Decrement our remaining fresh count
                        q.push({nr, nc}); // Add to queue for the next minute
                    }
                }
            }
            // Increment time after processing all oranges for the current minute
            time++; 
        }

        // Step 3: Check if any fresh oranges survived
        return freshCount == 0 ? time : -1;
    }
};
