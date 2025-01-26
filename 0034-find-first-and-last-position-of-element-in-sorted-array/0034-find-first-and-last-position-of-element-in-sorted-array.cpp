class Solution {
public:
    int first(vector<int>& nums, int target){
        int low=0,high=nums.size()-1,first=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]<target)
                low=mid+1;
            else 
                high=mid-1;
        }
        return first;
    }

    int second(vector<int>& nums, int target){
        int low=0,high=nums.size()-1,second=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                second=mid;
                low=mid+1;
            }
            else if(nums[mid]<target)
                low=mid+1;
            else 
                high=mid-1;
        }
        return second;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        v.push_back(first(nums,target));
        v.push_back(second(nums,target));
        return v;
    }
};