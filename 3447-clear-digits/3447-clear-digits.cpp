class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        for(auto it:s){
            if(it>='0' && it<='9'){
                ans.pop_back();
            }
            else ans+=it;
        }
        return ans;
    }
};