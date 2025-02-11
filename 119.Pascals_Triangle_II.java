class Solution {
  public List<Integer> getRow(int numRows) {
    List<Integer> oneRow = new ArrayList<>(1);
    oneRow.add(1);
    List<Integer> twoRow = new ArrayList<>(2);
    twoRow.add(1);
    twoRow.add(1);
    if (numRows == 0) {
      return oneRow;
    } else if (numRows == 1) {
      return twoRow;
    } else {
      List<Integer> latest = twoRow;
      for (int i = 2; i <= numRows; ++i) {
        List<Integer> newArr = new ArrayList<>();
        newArr.add(1);
        for (int first = 0, second = 1; second < latest.size(); ++first, ++second) {
          newArr.add(latest.get(first) + latest.get(second));
        }
        newArr.add(1);
        latest = newArr;
      }
      return latest;
    }
  }
}
