class Solution {
private:
    int solve(vector<int>& nums, int n, vector<int>& dp){
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        if(dp[n]!=-1) return dp[n];
        for(int i=2;i<=n;i++){
            int pick=nums[i]+dp[i-2];
            int notPick=dp[i-1];
            dp[i]=max(pick,notPick);
        }
        return dp[n];
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> points(maxi+1,0);
        for(auto it:nums){
            points[it]+=it;
        }
        vector<int> dp(maxi+1,-1);
        return solve(points,maxi,dp);
    }
};