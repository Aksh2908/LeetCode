class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n>=INT_MIN && n<=INT_MAX){
            if(n==0 || n<0) return 0;
            if(n&n-1) return 0;
            return 1;
        }
        return 0;
    }
};