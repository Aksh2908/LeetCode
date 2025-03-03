class Solution {
public:
    void parition(vector<int>& nums, int pivot){
        int n=nums.size();
        vector<int> less,equal,greater;
        for(auto it:nums){
            if(it<pivot) less.push_back(it);
            else if(it==pivot) equal.push_back(it);
            else greater.push_back(it); 
        }

        nums.clear();
        nums.insert(nums.end(),less.begin(),less.end());
        nums.insert(nums.end(),equal.begin(),equal.end());
        nums.insert(nums.end(),greater.begin(),greater.end());
    }
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        parition(nums,pivot);
        return nums;
    }
};