class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int len=nums.size();
        int n=len/2;
        map<int,int> mpp;
        int i;
        for(i=0;i<len;i++){
            mpp[nums[i]]++;
        }
        int ans;
        for(auto it:mpp){
            if(it.second==n){
                ans=it.first;
                break;
            }
        }
        return ans;
    }
};