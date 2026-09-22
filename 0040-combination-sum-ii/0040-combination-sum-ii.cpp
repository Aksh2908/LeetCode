class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int target, int idx){
        if(idx>=nums.size() || target==0){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
            for(int i=idx;i<nums.size();i++){
                if(i>idx && nums[i]==nums[i-1]) continue;
                if(nums[i]>target) break;
                temp.push_back(nums[i]);
                solve(nums,ans,temp,target-nums[i],i+1);
                temp.pop_back();
            }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(),candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates,ans,temp,target,0);

        return ans;
    }
};