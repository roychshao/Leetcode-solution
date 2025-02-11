class Solution {

  public int min(int a, int b) {
    return (a < b) ? a : b;
  }

  public int minimumTotal(List<List<Integer>> triangle) {
    int size = triangle.size();
    int[] dp = new int[triangle.get(size - 1).size()];
    for (int i = 0; i < dp.length; ++i) {
      dp[i] = triangle.get(size - 1).get(i);
    }
    for (int i = triangle.size() - 2; i >= 0; --i) {
      for (int j = 0; j <= i; ++j) {
        dp[j] = min(triangle.get(i).get(j) + dp[j], triangle.get(i).get(j) + dp[j + 1]);
      }
    }
    return dp[0];
  }
}
