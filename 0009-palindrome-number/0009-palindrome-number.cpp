class Solution {
public:
    bool isPalindrome(int x) {
        long long temp=x,rev=0;
        if(x<0) return 0;
        while(x){
            rev=rev*10+x%10;
            x/=10;
        }
        return temp==rev;
    }
};