class Solution {
	public:
	
	int n, m;
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	
	bool check(int nx, int ny, vector<vector<int>> & grid, vector<vector<int>> & vis) {
		return nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && !vis[nx][ny];
	}
	
	void dfs(int x, int y, vector<vector<int>> & grid, vector<vector<int>> & vis) {
		vis[x][y] = 1;
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (check(nx, ny, grid, vis)) {
				dfs(nx, ny, grid, vis);
			}
		}
	}
	
	int cntOnes(vector<vector<int>> & grid) {
		n = grid.size();
		m = grid[0].size();
		
		vector<vector<int>> vis(n, vector<int>(m, 0));
		
		for (int i = 0; i < n; i++) {
			if (grid[i][0] == 1 && !vis[i][0])
				dfs(i, 0, grid, vis);
			if (grid[i][m - 1] == 1 && !vis[i][m - 1])
				dfs(i, m - 1, grid, vis);
		}
		
		for (int j = 0; j < m; j++) {
			if (grid[0][j] == 1 && !vis[0][j])
				dfs(0, j, grid, vis);
			if (grid[n - 1][j] == 1 && !vis[n - 1][j])
				dfs(n - 1, j, grid, vis);
		}
		

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j]&&!vis[i][j]) {
					cnt++;
				}
			}
		}
		
		return cnt;
	}
};
