class Solution {
public:
    map<char,int> hashed(string s){
        map<char,int> mpp;
        for(auto it:s){
            mpp[it]++;
        }
        return mpp;
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string str="";
        for(auto it:licensePlate){
            if(isalpha(it)){
                str+=tolower(it);
            }
        }
        int mini=INT_MAX,flag=0;
        string minis="";
        map<char,int> mpp_s=hashed(str);
        int i;
        for(i=0;i<words.size();i++){
            flag=1;
            map<char,int> mpp_word=hashed(words[i]);
            for(auto it:mpp_s){
                if(mpp_word[it.first]<it.second){
                    flag=0;
                    break;
                }
            }
            if(flag && mini>words[i].length()){
                mini=words[i].length();
                minis=words[i];
            }
        }
        return minis;
    }
};