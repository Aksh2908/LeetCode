class Solution {
private:
    int solve(vector<int>& nums, int n,vector<int> &dp){
        dp[0]=nums[0];
        for(int i=1;i<=n;i++){
            int pick=nums[i];
            if(i>1) pick+=dp[i-2];
            int notPick=dp[i-1];
            dp[i]=max(pick,notPick);
        }
        return dp[n];
    }

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> dp(n,-1);
        return solve(nums,n-1,dp);
    }
};