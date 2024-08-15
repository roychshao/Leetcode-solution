class Solution {

    private int five = 0;
    private int ten = 0;

    public boolean lemonadeChange(int[] bills) {
        for (int i = 0; i < bills.length; ++i) {
            if (bills[i] == 5) {
                five++;
            } else if (bills[i] == 10) {
                if (five >= 1) {
                    ten++;
                    five--;
                } else {
                    return false;
                }
            } else if (bills[i] == 20) {
                if (five >= 1 && ten >= 1) {
                    five--;
                    ten--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
}
