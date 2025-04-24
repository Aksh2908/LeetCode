class Solution {
public:
    int longestOnes(vector<int>& nums,int k) {
        int l=0,r=0,n=nums.size();
        int maxLen=0;
        int cnt=0;
        while(r<n){
            if(nums[r]==0) cnt++;
            // while(cnt>k){
            //     if(nums[l]==0) cnt--;
            //     l++;
            // }
            if(cnt>k){
                if(nums[l]==0) cnt--;
                l++;
            }
            else{
                maxLen=max(maxLen,r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};