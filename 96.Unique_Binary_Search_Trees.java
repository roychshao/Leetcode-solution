import java.math.BigInteger;

class Solution {
    public int numTrees(int n) {
        // Calculate nth Catalan number
        BigInteger catalanNumber = choose(2*n, n).divide(BigInteger.valueOf(n + 1));
        return catalanNumber.intValue();
    }

    public BigInteger factorial(int n) {
        BigInteger fact = BigInteger.ONE;
        for (int i = 2; i <= n; ++i) {
            fact = fact.multiply(BigInteger.valueOf(i));
        }
        return fact;
    }

    public BigInteger choose(int n, int k) {
        if (k > n) return BigInteger.ZERO;
        return factorial(n).divide(factorial(k).multiply(factorial(n - k)));
    }
}

