import java.util.*;

class Solution {

    // All 8 possible knight moves
    private static final int[] dx = {2, 1, -1, -2, -2, -1, 1, 2};
    private static final int[] dy = {1, 2, 2, 1, -1, -2, -2, -1};

    public ArrayList<ArrayList<Integer>> knightTour(int n) {
        int[][] board = new int[n][n];
        for (int[] row : board) Arrays.fill(row, -1);

        // Start from (0, 0)
        board[0][0] = 0;

        // Try to find a solution using backtracking
        if (solve(board, n, 0, 0, 1)) {
            return convertToList(board);
        } else {
            return new ArrayList<>();
        }
    }

    private boolean solve(int[][] board, int n, int x, int y, int moveCount) {
        // Base case: if all squares are visited
        if (moveCount == n * n) return true;

        for (int i = 0; i < 8; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (isValid(board, n, nextX, nextY)) {
                board[nextX][nextY] = moveCount;
                if (solve(board, n, nextX, nextY, moveCount + 1))
                    return true;
                // Backtrack
                board[nextX][nextY] = -1;
            }
        }

        return false;
    }

    private boolean isValid(int[][] board, int n, int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == -1);
    }

    private ArrayList<ArrayList<Integer>> convertToList(int[][] board) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        for (int[] row : board) {
            ArrayList<Integer> temp = new ArrayList<>();
            for (int val : row) temp.add(val);
            result.add(temp);
        }
        return result;
    }

    // For quick local testing
    public static void main(String[] args) {
        Solution sol = new Solution();
        int n = 5;
        ArrayList<ArrayList<Integer>> ans = sol.knightTour(n);
        if (ans.isEmpty()) {
            System.out.println("[]");
        } else {
            for (ArrayList<Integer> row : ans) {
                System.out.println(row);
            }
        }
    }
}
