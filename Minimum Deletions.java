class Solution {
    static int minDeletions(String s) {
        int n = s.length();
        String rev = new StringBuilder(s).reverse().toString();
        return n - longestCommonSubsequence(s, rev);
    }

    private static int longestCommonSubsequence(String a, String b) {
        int n = a.length();
        int[][] dp = new int[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a.charAt(i - 1) == b.charAt(j - 1))
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][n];
    }
}

