class Solution {
public:
    bool possible(vector<int>& v, int day, int k, int m){
        int i,cnt=0,n=v.size(),ans=0;
        for(i=0;i<n;i++){
            if(v[i]<=day){
                cnt++;
            }
            else{
                ans+=cnt/k;
                cnt=0;
            } 
        }
        ans+=cnt/k;
        return ans>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int i,ans=-1,n=bloomDay.size();
        long long val=(long long)(m)*(long long)(k);
        if(val>n) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());  
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay,mid,k,m))
                high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};