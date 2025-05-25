class Solution {
private:
    int solve(vector<int>& nums, int n, vector<int>& dp){
        if(n==0) return nums[0];
        if(n==1) return max(nums[0],nums[1]);
        if(dp[n]!=-1) return dp[n];
        int pick=nums[n]+solve(nums,n-2,dp);
        int notPick=solve(nums,n-1,dp);
        return dp[n]=max(pick,notPick);
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