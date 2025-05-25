class Solution {
private:
    int solve(vector<int>& nums, int n){
        int prev1=nums[0];
        int prev=max(nums[0],nums[1]);
        int curr=0;
        for(int i=2;i<=n;i++){
            int pick=nums[i]+prev1;
            int notPick=prev;
            curr=max(pick,notPick);
            prev1=prev;
            prev=curr;
        }
        return prev;
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
        return solve(points,maxi);
    }
};