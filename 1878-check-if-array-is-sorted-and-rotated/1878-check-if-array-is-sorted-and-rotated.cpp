class Solution {
private:
    bool isSorted(vector<int>& nums, int start,int end){
        for(int i=start;i<end;i++){
            if(nums[i]>nums[i+1]) return false;
        }
        return true;
    }
public:
    bool check(vector<int>& nums) {
        int pivot=-1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]<nums[i-1]) pivot=i;
        }
        if(pivot==-1) return true;
        if(isSorted(nums,0,pivot-1) && isSorted(nums,pivot,nums.size()-1) && nums[nums.size()-1]<=nums[0]) return true;
        return false;
    }
};