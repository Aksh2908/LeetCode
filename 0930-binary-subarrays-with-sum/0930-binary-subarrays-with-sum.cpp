class Solution {
private:
    int cnt(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int n=nums.size();

        long long sum=0,cnt=0;

        int l=0,r=0;

        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return cnt(nums,goal)-cnt(nums,goal-1);
    }
};