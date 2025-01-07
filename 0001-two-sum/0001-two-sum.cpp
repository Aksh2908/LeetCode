class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int,int> mpp;
        vector <int> res;
        int i,n=nums.size();
        for(i=0;i<n;i++){
            if(mpp.find(target-nums[i])!= mpp.end()) {
                res.push_back(i);
                res.push_back(mpp.find(target-nums[i])->second);
            }
            mpp[nums[i]]=i;
        }
        return res;
    }
};