class Solution {
    public int celebrity(int[][] mat) {
        int n = mat.length;
        Stack<Integer> stack = new Stack<>();

        // Step 1: Push all people into the stack
        for (int i = 0; i < n; i++) {
            stack.push(i);
        }

        // Step 2: Eliminate non-celebrities
        while (stack.size() > 1) {
            int a = stack.pop();
            int b = stack.pop();

            if (knows(mat, a, b)) {
                // a knows b → a can't be celebrity
                stack.push(b);
            } else {
                // a doesn't know b → b can't be celebrity
                stack.push(a);
            }
        }

        // Step 3: Verify the remaining candidate
        int candidate = stack.pop();
        for (int i = 0; i < n; i++) {
            if (i == candidate) continue;
            if (knows(mat, candidate, i) || !knows(mat, i, candidate)) {
                return -1;
            }
        }

        return candidate;
    }

    // Helper function
    private boolean knows(int[][] mat, int i, int j) {
        return mat[i][j] == 1;
    }
}
