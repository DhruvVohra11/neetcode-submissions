class Solution {
public:
    void island(vector<vector<char>> & grid, set<pair<int, int>> & vis, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        
        if(grid[i][j] == '0') return;
        
        if(vis.count({i, j})) return;

        vis.insert({i,j});
        island(grid, vis, i+1, j);
        island(grid, vis, i-1, j);
        island(grid, vis, i, j+1);
        island(grid, vis, i, j-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        set<pair<int, int>> vis;
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '0'){
                    vis.insert({i,j});
                    continue;
                }
                else if(grid[i][j] == '1' && !vis.count({i,j})){
                    island(grid, vis, i, j);
                    count++;
                }
                else{
                    
                }
            }
        }
        return count;
    }
};