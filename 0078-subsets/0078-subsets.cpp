class Solution {
public:
    void func(int idx,vector<vector<int>> &ans, vector<int> res, vector<int> nums){
        if(idx>=nums.size()){
            ans.push_back(res);
            return;
        }
        res.push_back(nums[idx]);
        func(idx+1,ans,res,nums);
        res.pop_back();
        func(idx+1,ans,res,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        func(0,ans,res,nums);
        return ans;
    }
};