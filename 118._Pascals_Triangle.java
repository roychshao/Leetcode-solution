class Solution {
  public List<List<Integer>> generate(int numRows) {
    List<List<Integer>> result = new ArrayList<>();
    List<Integer> oneRow = new ArrayList<>(1);
    oneRow.add(1);
    List<Integer> twoRow = new ArrayList<>(2);
    twoRow.add(1);
    twoRow.add(1);
    if (numRows == 1) {
      result.add(new ArrayList<>(oneRow));
      return result;
    } else if (numRows == 2) {
      result.add(new ArrayList<>(oneRow));
      result.add(new ArrayList<>(twoRow));
      return result;
    } else {
      result.add(new ArrayList<>(oneRow));
      result.add(new ArrayList<>(twoRow));
      List<Integer> latest = twoRow;
      for (int i = 3; i <= numRows; ++i) {
        List<Integer> newArr = new ArrayList<>();
        newArr.add(1);
        for (int first = 0, second = 1; second < latest.size(); ++first, ++second) {
          newArr.add(latest.get(first) + latest.get(second));
        }
        newArr.add(1);
        result.add(new ArrayList<>(newArr));
        latest = newArr;
      }
      return result;
    }
  }
}
