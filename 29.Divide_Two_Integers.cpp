class Solution {
public:
    int divide(int a, int b) {
        // return a / b without using /,*,%
        if(a==INT_MIN && b==-1) return INT_MAX;
        if(a==INT_MIN && b==1) return INT_MIN;     
        long int la = abs(a), lb = abs(b);
        int sign = ((a > 0 && b > 0) || (a < 0 && b < 0)) ? 1 : -1;
        long long counter = 0;
        while(la >= lb) {
            long int mul = lb, tmp = 1;
            while(mul<=la-mul) {
                mul += mul;
                tmp += tmp;
            }
            counter += tmp;
            la -= mul;
        }
        if (sign < 0)
            return (0 - counter);
        else
            return counter;
    }
};
