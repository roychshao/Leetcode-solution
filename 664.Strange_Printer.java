class Solution {

    private String removeDuplicates(String s) {
        StringBuilder uniqueChars = new StringBuilder();
        int i = 0;
        while (i < s.length()) {
            char currentChar = s.charAt(i);
            uniqueChars.append(currentChar);
            // Skip all consecutive occurrences of the current character
            while (i < s.length() && s.charAt(i) == currentChar) {
                i++;
            }
        }
        return uniqueChars.toString();
    }

    private int minimumTurns(int i, int j, String s, Integer[][] memo) {
        if (i > j)
            return 0;
        if (memo[i][j] != null)
            return memo[i][j];

        int minTurns = 1 + minimumTurns(i + 1, j, s, memo);
        for (int k = i + 1; k <= j; k++) {
            if (s.charAt(k) == s.charAt(i)) {
                minTurns = Math.min(minTurns, minimumTurns(i, k - 1, s, memo) + minimumTurns(k + 1, j, s, memo));
            }
        }
        return memo[i][j] = minTurns;
    }

    public int strangePrinter(String s) {
        s = removeDuplicates(s);
        int n = s.length();
        Integer[][] memo = new Integer[n][n];
        return minimumTurns(0, n - 1, s, memo);
    }
}
