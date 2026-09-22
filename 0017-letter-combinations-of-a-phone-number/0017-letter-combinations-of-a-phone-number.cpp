class Solution {
private:
    void generate(string digits, vector<string>& mpp, vector<string>& ans, string temp, int idx, int n){
        if(idx==n || temp.size()==n){
            if(temp.size()==n){
                ans.push_back(temp);
            }
            return;
        }
        string s=mpp[digits[idx]-'0'];

        for(auto it:s){
            temp+=it;
            generate(digits,mpp,ans,temp,idx+1,n);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> mpp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        vector<string> ans;
        string temp="";

        generate(digits,mpp,ans,temp,0,digits.size());
        return ans;
    }
};