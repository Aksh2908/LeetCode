class Solution {
public:
    bool isPowerOfFour(int n) {
        double logVal=log(n)/log(4);
        if(n<=0) return false;
        if(logVal==(int)logVal) return true;
        return false;
    }
};