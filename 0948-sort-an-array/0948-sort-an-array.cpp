class Solution {
public:

    void merge(vector<int> &nums, int low, int mid, int high){
        int left=low,right=mid+1;
        vector<int> ans;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                ans.push_back(nums[left]);
                left++;
            }
            else{
                ans.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            ans.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            ans.push_back(nums[right]);
            right++;
        }
        for (int i = low; i <= high; i++) {
            nums[i] = ans[i - low];
        }
    }
    
    void mergeSort(vector<int>& nums, int low, int high){
        if(low>=high) return;
        int mid=(low+high)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};