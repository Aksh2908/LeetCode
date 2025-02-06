class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto it:nums){
            st.insert(it);
        }
        int x,cnt,longest=0;
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                x=it;
                cnt=1;
                while(st.find(x+1)!=st.end()){
                    x+=1;
                    cnt++;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};