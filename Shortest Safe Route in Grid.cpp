class Solution {
	private:
	vector<int>drow {-1, 1, 0, 0};
	vector<int>dcol {0, 0, -1, 1};
	public:
	int shortestPath(vector<vector<int>> &mat) {
		// code here
		int n = mat.size(), m = mat[0].size();
		int result = 1e9;
		vector<vector<int>> dist(n, vector<int>(m, 1e9));
		queue<pair<int, int>> q;
		
		for (int i = 0; i<n; ++i) {
			for (int j = 0; j<m; ++j) {
				if (mat[i][j] == 0) {
					dist[i][j] = -1e9;
					for (int k = 0; k<4; ++k) {
						int nrow = i + drow[k];
						int ncol = j + dcol[k];
						if (nrow >= 0 && nrow<n && ncol >= 0
						 && ncol<m) {
							dist[nrow][ncol] = -1e9;
						}
					}
				}
			}
		}
		for (int i = 0; i<n; ++i) {
			if (mat[i][0] == 1 && dist[i][0] == 1e9) {
				q.push({i, 0});
				dist[i][0] = 1;
			}
		}
		while (!q.empty()) {
			int row = q.front().first, col = q.front().second;
			q.pop();
			if (col == m - 1) {
				result = min(result, dist[row][col]);
			}
			for (int k = 0; k<4; ++k) {
				int nrow = row + drow[k];
				int ncol = col + dcol[k];
				if (nrow >= 0 && nrow<n && ncol >= 0
				 && ncol<m) {
					if (dist[row][col]+1<dist[nrow][ncol]) {
						dist[nrow][ncol] = dist[row][col]+1;
						q.push({nrow, ncol});
					}
				}
			}
		}
		if (result == 1e9)return - 1;
		return result;
	}
};
