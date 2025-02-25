class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        int i=0,cnt=0;
        string ans="";
        while(i<n){
            if(s[i]=='('){
                if(cnt>0)
                    ans+=s[i];
                cnt++;
            }
            else{
                cnt--;
                if(cnt>0){
                    ans+=s[i];
                }
            }
            i++;
        }
        return ans;
    }
};