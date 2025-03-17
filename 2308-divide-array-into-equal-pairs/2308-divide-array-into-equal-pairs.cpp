class Solution {
public:
    bool divideArray(vector<int>& nums) {
       unordered_map<int,int> mpp;
       for(auto it:nums){
        mpp[it]++;
       } 
       int cnt=0;
       for(auto it:mpp){
        if(it.second%2) return false;
        else cnt+=(it.second/2);
       }
       int n=nums.size();
       return cnt==(n/2);
    }
};