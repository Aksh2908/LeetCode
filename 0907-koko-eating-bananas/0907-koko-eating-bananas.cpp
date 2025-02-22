class Solution {
public:
    bool eatTime(int k, int h,vector<int> piles){
        int totalHours=0,n=piles.size();
        int i;
        for(i=0;i<n;i++){
            totalHours+=ceil((double)piles[i]/k);
            if(totalHours>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end());
        int ans;
        while(low<=high){
            int mid=(low+high)/2;
            if(eatTime(mid,h,piles)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};