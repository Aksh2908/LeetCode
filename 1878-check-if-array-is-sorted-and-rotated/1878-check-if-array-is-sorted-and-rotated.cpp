class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0,i,n=nums.size();
        for(i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]) cnt++;
        }
        return cnt<=1;
    }
};