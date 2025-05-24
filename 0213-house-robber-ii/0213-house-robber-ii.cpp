class Solution {
private:
    int solve(vector<int>& nums, int start, int end, vector<int>& dp){
        if(start>end) return 0;
        if(dp[start]!=-1) return dp[start];
        int pick=nums[start]+solve(nums,start+2,end,dp);
        int notPick=solve(nums,start+1,end,dp);
        return dp[start]=max(pick,notPick); 
    }

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        return max(solve(nums,0,n-2,dp1),solve(nums,1,n-1,dp2));
    }
};