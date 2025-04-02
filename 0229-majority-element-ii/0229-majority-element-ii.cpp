class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n=nums.size();
        for(auto it:nums) mpp[it]++;
        vector<int> ans;
        for(auto it:mpp){
            if(it.second>n/3)
                ans.push_back(it.first);
        } 
        return ans;
    }
};