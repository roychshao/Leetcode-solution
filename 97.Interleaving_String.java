class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        
        boolean [][] paths = new boolean[s1.length() + 1][s2.length() + 1];
        paths[0][0] = true;
        
        // 是否能一路到
        for (int i = 1; i <= s1.length(); ++i) {
            paths[i][0] = paths[i-1][0] && s1.charAt(i-1) == s3.charAt(i-1);
        }
        for (int j = 1; j <= s2.length(); ++j) {
            paths[0][j] = paths[0][j-1] && s2.charAt(j-1) == s3.charAt(j-1);
        }

        for (int i = 1; i <= s1.length(); ++i) {
            for (int j = 1; j <= s2.length(); ++j) {
                paths[i][j] = (paths[i-1][j] && s1.charAt(i-1) == s3.charAt(i+j-1)) || (paths[i][j-1] && s2.charAt(j-1) == s3.charAt(i+j-1));
            }
        }
        return paths[s1.length()][s2.length()];
    }
}
