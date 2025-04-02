class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        vector<int> ans(2,-1);
        for(int i=0;i<nums.size();i++){
            auto res=mpp.find(target-nums[i]);
            if(res!=mpp.end()){
                ans[0]=i;
                ans[1]=res->second;
                return ans;
            }
            else mpp[nums[i]]=i;
        }
        return ans;
    }
};