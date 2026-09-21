class Solution {
private:
    void generate(vector<string>& ans, string &temp, int n, int previous){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        
        if(previous==1){
            temp+='0';
            generate(ans,temp,n,0);
            
            temp.pop_back();
            
            temp+='1';
            generate(ans,temp,n,1);
            temp.pop_back();
        }
        else{
            temp+='1';
            generate(ans,temp,n,1);
            temp.pop_back();
        }
    }
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        string temp="";

        generate(ans,temp,n,1);

        return ans;
    }
};