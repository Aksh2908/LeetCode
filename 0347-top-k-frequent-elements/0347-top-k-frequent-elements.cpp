class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        vector<pair<int,int>> vec(mpp.begin(),mpp.end());
        sort(vec.begin(),vec.end(),[](const pair<int, int>& a, const pair<int, int>& b){
            return a.second>b.second;
        });
        vector<int> ans;
        int cnt=1;
        for(auto it:vec){
            if(cnt<=k){
                ans.push_back(it.first);
                cnt++;
            }
            else break;
        }
        return ans;
    }
};