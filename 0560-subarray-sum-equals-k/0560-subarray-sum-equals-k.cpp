class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0,cnt=0;
        map<long,long> preSum; // sum,freq
        preSum[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum-k;
            cnt+=preSum[rem];
            preSum[sum]++;
        }
        return cnt;
    }
};