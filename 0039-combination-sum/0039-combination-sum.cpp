class Solution {
public:
    void findComb(int idx, vector<int> ds, vector<vector<int>> &ans, vector<int> candidates, int target){
        if(idx==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[idx]<=target){
            ds.push_back(candidates[idx]);
            findComb(idx,ds,ans,candidates,target-candidates[idx]);
            ds.pop_back();
        }
        findComb(idx+1,ds,ans,candidates,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        findComb(0,ds,ans,candidates,target);
        return ans;
    }
};