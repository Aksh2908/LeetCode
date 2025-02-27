class Solution {
public:
    int totalSubArrays(vector<int>& nums, int sum){
        int subArrays=1,totalSum=0;
        for(auto it:nums){
            if(totalSum+it>sum){
                subArrays++;
                totalSum=it;
            }
            else totalSum+=it;
        }
        return subArrays;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            if(totalSubArrays(nums,mid)>k) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};