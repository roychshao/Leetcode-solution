class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> crnt = new ArrayList<>(Arrays.asList(0, 1));
        if (n == 1) {
            return crnt;
        }
        crnt = grayCode(n - 1);
        List<Integer> ret = new ArrayList<>();
        int add = (int) Math.pow(2, n-1); // the most significant bit
        for (int i = crnt.size()-1; i >= 0; i--) {
            crnt.add(crnt.get(i)+add);
        }
    }
}
