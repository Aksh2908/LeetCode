class Solution {
public:
    int Pos(vector<int>& nums){
        int pos=-1;
        int low=0,high=nums.size()-1,mid;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]>0){
                pos=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return pos==-1?0:nums.size()-pos;
    }
    int Neg(vector<int>& nums){
        int neg=-1;
        int low=0,high=nums.size()-1,mid;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]<0){
                neg=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return neg==-1?0:neg+1;
    }
    int maximumCount(vector<int>& nums) {
        int pos=Pos(nums);
        int neg=Neg(nums);
        return max(pos,neg);
    }
};