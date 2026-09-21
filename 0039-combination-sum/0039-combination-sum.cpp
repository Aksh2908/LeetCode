class Solution {
private:
    void solve(vector<int>& nums, int target, vector<vector<int>>& ans, vector<int>& temp, int sum, int idx){
        if(idx>=nums.size() || sum>target){
            if(sum==target){
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back(nums[idx]);
        solve(nums,target,ans,temp,sum+nums[idx],idx);
        temp.pop_back();
        solve(nums,target,ans,temp,sum,idx+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,target,ans,temp,0,0);
        return ans;
    }
};