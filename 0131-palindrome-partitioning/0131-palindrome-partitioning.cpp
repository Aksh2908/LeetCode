class Solution {
private:
    bool isPalindrome(string &s, int idx, int i){
        while(idx<=i){
            if(s[idx]!=s[i]) return false;
            idx++;
            i--;
        }
        return true;
    }
    void solve(string &s, vector<vector<string>>& ans, vector<string>& temp, int idx){
        if(idx==s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=idx;i<s.size();i++){
            if(isPalindrome(s,idx,i)){
                string st=s.substr(idx,i-idx+1);
                temp.push_back(st);
                solve(s,ans,temp,i+1);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        solve(s,ans,temp,0);

        return ans;
    }
};