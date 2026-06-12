class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 1. Check Rows
        for (int i = 0; i < 9; i++) {
            unordered_set<char> rowSet;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (rowSet.count(board[i][j])) return false;
                rowSet.insert(board[i][j]);
            }
        }

        // 2. Check Columns
        for (int i = 0; i < 9; i++) {
            unordered_set<char> colSet;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue; // Note the [j][i] for columns
                if (colSet.count(board[j][i])) return false;
                colSet.insert(board[j][i]);
            }
        }

        // 3. Check 3x3 Boxes
        // We move in jumps of 3 to find the top-left corner of each box
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                unordered_set<char> boxSet;
                // Check the 3x3 area starting from (row, col)
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char val = board[row + i][col + j];
                        if (val == '.') continue;
                        if (boxSet.count(val)) return false;
                        boxSet.insert(val);
                    }
                }
            }
        }

        return true;
    }
};