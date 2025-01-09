class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2) return 0;
        int i;
        stack<char> st;
        for(i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else{
                if(st.empty()) return 0;
                else{
                    if((s[i]==')' && st.top()=='(') || (s[i]==']' && st.top()=='[') || (s[i]=='}' && st.top()=='{')) st.pop();
                    else return 0;
                }
            }
        }
        if(!st.empty()) return 0;
        return 1;
    }
};