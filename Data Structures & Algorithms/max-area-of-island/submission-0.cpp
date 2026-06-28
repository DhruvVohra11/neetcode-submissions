class Solution {
public:
    int island(vector<vector<int>> & grid, set<pair<int, int>> & vis, int i, int j, int s){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return 0;
        
        if(grid[i][j] == 0) return 0;
        
        if(vis.count({i, j})) return 0;

        vis.insert({i,j});
        
        return 1+island(grid, vis, i+1, j,s)+island(grid, vis, i-1, j,s)+island(grid, vis, i, j+1,s)+island(grid, vis, i, j-1,s);
        
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        set<pair<int, int>> vis;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    vis.insert({i,j});
                    continue;
                }
                else if(grid[i][j] == 1 && !vis.count({i,j})){
                    max = std::max(max,island(grid, vis, i, j, 1));
                }
                else{
                    
                }
            }
        }
        return max;  
    }
};
