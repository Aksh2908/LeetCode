class Solution {
private:
    int solve(int n,vector<int>& dp){
        if(n<=1) return 1;
        int prev1=1;
        int prev=1;
        for(int i=2;i<=n;i++){
            int curr=prev+prev1;
            prev1=prev;
            prev=curr;
        }
        return prev;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};