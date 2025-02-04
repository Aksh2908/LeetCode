class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i;
        long long sum=0,maxi=LONG_MIN;
        for(i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0) sum=0;
        }
        return (int)maxi;
    }
};