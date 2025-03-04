class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int i,n=nums.size();
        vector<int> ans(n,-1);
        for(i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i%n])
                st.pop();
            if(i<n){
                ans[i]=st.empty() ? -1 : st.top();
            }
            st.push(nums[i%n]);
        }
        return ans;
    }
};