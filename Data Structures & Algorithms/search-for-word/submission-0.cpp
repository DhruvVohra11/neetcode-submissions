#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (bfs(board, i, j, word)) return true;
                }
            }
        }
        return false;
    }

    bool bfs(vector<vector<char>>& board, int i, int j, string word) {
        if (word.length() == 1) return true;

        int m = board.size();
        int n = board[0].size();

        // Node state: {row, col, next_char_index, path_visited_set}
        struct State {
            int r, c, nxt;
            set<pair<int, int>> visited;
        };

        queue<State> q;
        q.push({i, j, 1, {{i, j}}});

        vector<int> nr = {1, -1, 0, 0};
        vector<int> nc = {0, 0, -1, 1};

        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            if (top.nxt == word.length()) {
                return true;
            }

            for (int d = 0; d < 4; d++) {
                int newr = top.r + nr[d];
                int newc = top.c + nc[d];

                // 1. Check boundary using proper row (m) and col (n) bounds
                if (newr < 0 || newr >= m || newc < 0 || newc >= n) {
                    continue;
                }

                // 2. Check if cell is already visited in this path
                if (top.visited.count({newr, newc})) {
                    continue;
                }

                // 3. Check character match
                if (board[newr][newc] == word[top.nxt]) {
                    auto next_visited = top.visited;
                    next_visited.insert({newr, newc});

                    if (top.nxt + 1 == word.length()) return true;

                    q.push({newr, newc, top.nxt + 1, next_visited});
                }
            }
        }

        return false;
    }
};