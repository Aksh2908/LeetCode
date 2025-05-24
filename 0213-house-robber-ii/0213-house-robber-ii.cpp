class Solution {
private:
    int solve(vector<int>& nums, int start, int end, vector<int>& dp){
        //if(dp[start]!=-1) return dp[start];
        for(int i=end;i>=start;i--){
            int pick=nums[i]+dp[i+2];
            int notPick=dp[i+1]; 
            dp[i]=max(pick,notPick);
        }
        return dp[start]; 
    }

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n+2,0);
        vector<int> dp2(n+2,0);
        return max(solve(nums,0,n-2,dp1),solve(nums,1,n-1,dp2));
    }
};