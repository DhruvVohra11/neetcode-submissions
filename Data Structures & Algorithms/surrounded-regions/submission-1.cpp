class Solution {
public:
    void bfs(vector<vector<char>> & b, int i, int j){
        queue<pair<int, int>> q;
        q.push({i,j});
        vector<pair<int,int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        vector<pair<int,int>> vis;
        vis.push_back({i,j});
        b[i][j] = 'X'; 
        
        bool flag = false;
        
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            
            for(auto dir: directions){
                int nr = top.first + dir.first;
                int nc = top.second + dir.second;

                if (nr < 0 || nr >= b.size() || nc < 0 || nc >= b[0].size()) {
                    continue;
                }

                if(b[nr][nc] == 'O' && (nr == b.size()-1 || nc == b[0].size()-1 || nr == 0 || nc == 0)){
                    flag = true;
                    vis.push_back({nr,nc});
                    b[nr][nc] = 'X'; 
                }
                else if(b[nr][nc] == 'O'){
                    vis.push_back({nr,nc});
                    b[nr][nc] = 'X'; 
                    q.push({nr,nc}); 
                }
            }
        }
         
        if(flag == true){
            for(auto x: vis){
                b[x.first][x.second] = 'O'; // Revert back to 'O' since it connects to border
            }
        }
        // If flag is false, they stay 'X' (already flipped during vis traversal)
    }
    
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i<m; i++){
            for(int j = 0 ; j<n ; j++){
                if( i == 0 || i == m-1 || j == 0 || j == n-1 ){
                    continue;
                }
                else if(board[i][j] == 'O'){
                    bfs(board,i,j);
                }
            }
        }
    }
};
