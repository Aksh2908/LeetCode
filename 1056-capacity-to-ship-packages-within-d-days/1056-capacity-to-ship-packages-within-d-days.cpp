class Solution {
public:
    bool daysRequired(vector<int>& v, int capacity, int days){
        int j,n=v.size();
        int sum=0,cnt=1;
        for(j=0;j<n;j++){
            if(sum+v[j]>capacity){
                cnt++;
                sum=v[j];
            }
            else sum+=v[j];
        }
        return (cnt<=days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int i;
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            if(daysRequired(weights,mid,days)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};