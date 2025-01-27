class Solution {
public:
    map<char,int> hashed(string s){
        map<char,int> mpp;
        for(auto it:s){
            mpp[it]++;
        }
        return mpp;
    }
    int countCharacters(vector<string>& words, string chars) {
        int flag,cnt=0;
        map<char,int> mpp_s=hashed(chars);
        int i;
        for(i=0;i<words.size();i++){
            flag=1;
            map<char,int> mpp_word=hashed(words[i]);
            for(auto it:mpp_word){
                if(mpp_s[it.first]<it.second){
                    flag=0;
                    break;
                }
            }
            if(flag){
                cnt+=words[i].length();
            }
        }
        return cnt;
    }
};