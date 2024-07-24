class Solution {

    public List<String> res = new ArrayList<String>();

    public boolean validNumber(String s) {
        if (s.startsWith("0") && s.length() > 1) {
            return false;
        }
        return Integer.parseInt(s) >= 0 && Integer.parseInt(s) <= 255;
    }

    public void backtracking(String s, String tmp, int remainNum) {
        if (remainNum == 0 && s.isEmpty()) {
            res.add(tmp);
            return;
        } else if (remainNum == 0 && !s.isEmpty()) {
            return;
        } else if (remainNum > 0 && s.isEmpty()) {
            return;
        } else {
            for (int i = 1; i <= Math.min(3, s.length()); ++i) {
                String num = s.substring(0, i);
                String remain = s.substring(i);
                // System.out.println(num);
                // System.out.println(remain);
                if (validNumber(num)) {
                    String newTmp = tmp;
                    if (remainNum != 1)
                        newTmp += num + ".";
                    else
                        newTmp += num;
                    // System.out.println(newTmp);
                    backtracking(remain, newTmp, remainNum - 1);
                }
            }
        }
    }

    public List<String> restoreIpAddresses(String s) {
        String tmp = "";
        backtracking(s, tmp, 4);
        return res;
    }
}
