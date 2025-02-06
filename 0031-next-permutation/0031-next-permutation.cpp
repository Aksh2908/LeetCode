class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakIdx=-1,i;
        for(i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                breakIdx=i-1;
                break;
            }
        }
        if(breakIdx==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        for(i=nums.size()-1;i>breakIdx;i--){
            if(nums[i]>nums[breakIdx]){
                swap(nums[breakIdx],nums[i]);
                break;
            }
        }
        reverse(nums.begin()+(breakIdx+1),nums.end());
}

};