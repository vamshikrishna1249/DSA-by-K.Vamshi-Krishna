class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> vis(r, vector<int>(c, 0));
        queue<pair<pair<int, int>, int>> q;

        int ans = 0;

        // Put all initially rotten oranges into the queue
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        // BFS
        while (!q.empty()) {
            int a = q.front().first.first;
            int b = q.front().first.second;
            int count = q.front().second;
            q.pop();

            ans = max(ans, count);

            // Up
            if (a > 0 && grid[a - 1][b] == 1 && !vis[a - 1][b]) {
                q.push({{a - 1, b}, count + 1});
                vis[a - 1][b] = 1;
            }

            // Down
            if (a + 1 < r && grid[a + 1][b] == 1 && !vis[a + 1][b]) {
                q.push({{a + 1, b}, count + 1});
                vis[a + 1][b] = 1;
            }

            // Left
            if (b  > 0 && grid[a][b - 1] == 1 && !vis[a][b - 1]) {
                q.push({{a, b - 1}, count + 1});
                vis[a][b - 1] = 1;
            }

            // Right
            if (b + 1 < c && grid[a][b + 1] == 1 && !vis[a][b + 1]) {
                q.push({{a, b + 1}, count + 1});
                vis[a][b + 1] = 1;
            }
        }

        // Check if any fresh orange remains
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    return -1;
                }
            }
        }

        return ans;
    }
};