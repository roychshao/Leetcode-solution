class Solution {
public:

    int findSqrt(long long head, long long tail, int x) {
        if(head == tail)
            return head;
        if(head == (tail - 1))
            return head;
        long long mid = (head + tail) / 2;
        long long tmp = mid * mid;
        return tmp > x ? findSqrt(head, mid, x) : findSqrt(mid, tail, x);
    }

    int mySqrt(int x) {
        if(x == 0)
            return 0;
        // 縮小搜尋範圍
        long long smallSqrt = 1;
        long long bigSqrt = smallSqrt * 2;
        while(x >= (bigSqrt * bigSqrt)) {
            smallSqrt = bigSqrt;
            bigSqrt *= 2;
        }
        // use merge sort's thought
        return findSqrt(smallSqrt, bigSqrt, x);
    }
};
