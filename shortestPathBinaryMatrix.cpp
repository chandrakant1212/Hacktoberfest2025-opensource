class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       int n = grid.size();
       if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
       queue<tuple<int,int,int>>q;
       q.push({0,0,1});
       set<pair<int,int>>visit;
       visit.insert({0,0});
       vector<pair<int, int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0},
            {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
        };
       while(!q.empty()){ //bfs
        auto [r,c,length] = q.front();
        q.pop();
        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] == 1) 
                continue;
        if (r == n - 1 && c == n - 1)
                return length;
        for (auto [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0 && 
                    visit.find({nr, nc}) == visit.end()) {
                    
                    visit.insert({nr, nc});
                    q.push({nr, nc, length + 1});
                }
            }
        }
        return -1;
    }
};
