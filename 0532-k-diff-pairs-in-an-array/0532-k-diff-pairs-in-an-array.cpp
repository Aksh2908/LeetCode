class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int cnt=0;
        for(auto it:nums) mpp[it]++;
        for(auto it:mpp){
            if(k==0){
                if(it.second>=2) cnt++;
            }
            else{
                if(mpp.find(it.first-k)!=mpp.end()) cnt++;
            }
        }
        return cnt;
    }
};