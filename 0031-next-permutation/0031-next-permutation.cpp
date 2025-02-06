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
        cout << breakIdx;
        if(breakIdx==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        int ngIdx=-1;
        for(i=breakIdx+1;i<nums.size();i++){
            if(nums[breakIdx]<nums[i]) ngIdx=i;
        }
        swap(nums[breakIdx],nums[ngIdx]);
        sort(nums.begin()+(breakIdx+1),nums.end());
}

};