class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int i,n=nums.size();
        int elt1,cnt1=0;
        int elt2,cnt2=0;
        for(i=0;i<n;i++){
            if(!cnt1 && nums[i]!=elt2){
                cnt1++;
                elt1=nums[i];
            }
            else if(!cnt2 && nums[i]!=elt1){
                cnt2++;
                elt2=nums[i];
            }
            else if(nums[i]==elt1) cnt1++;
            else if(nums[i]==elt2) cnt2++;
            else{
                cnt1--;cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(i=0;i<n;i++){
            if(nums[i]==elt1) cnt1++;
            else if(nums[i]==elt2) cnt2++;
        }
        if(cnt1>n/3) ans.push_back(elt1);
        if(cnt2>n/3) ans.push_back(elt2);
        return ans;
    }
};