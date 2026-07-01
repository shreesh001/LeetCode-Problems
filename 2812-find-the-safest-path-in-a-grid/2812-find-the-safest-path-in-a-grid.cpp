class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    bool check(const vector<vector<int>>& dist, int n, int max_dist) {
        if (dist[0][0] < max_dist || dist[n - 1][n - 1] < max_dist) return false;
        
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        
        q.push({0, 0});
        vis[0][0] = true;
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            if (r == n - 1 && c == n - 1) return true;
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc] && dist[nr][nc] >= max_dist) {
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return 0;

        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        // Multi-source BFS to calculate safeness distances
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == 1e9) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        int low = 0;
        int high = n * 2; 
        int ans = 0; 
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(dist, n, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};