class Solution {
public:
    int fresh;
    int time = 0;
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        fresh = 0;
        queue<pair<int, int>> q;
        int ans = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    fresh++;
                }
            }
        }
        if (fresh == 0)
            return 0;

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty() && fresh > 0) {
            
            int qs = q.size();
            time++;
            for (int i = 0; i < qs; i++) {

                auto top = q.front();
                q.pop();
                int r = top.first;
                int c = top.second;
                for (auto d : dir) {
                    int nr = r + d.first;
                    int nc = c + d.second;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    }
                }
            }
        }
        if (fresh > 0)
        return -1;
        return time;
    }
};