class Solution {
public:
    int calSum(vector<int> &nums, int i){
        int sum=0,n=nums.size(),k;
        for(k=0;k<n;k++){
            sum+=ceil((double)(nums[k])/(double)(i));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int i,n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end()),ans=0,sum=0;
        int low=1,high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            sum=calSum(nums,mid);
            if(sum<=threshold){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};