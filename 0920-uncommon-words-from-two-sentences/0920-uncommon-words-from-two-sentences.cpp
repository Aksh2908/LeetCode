class Solution {
public:
    unordered_map<string,int> hash_map_func(string s){
        unordered_map<string,int> mpp;
        int i;
        string word="";
        for(i=0;i<s.length();i++){
            if(s[i]==' '){
                mpp[word]++;
                word="";

            }
            else{
                word+=s[i];
            }
        }
        if(!word.empty()) {
            mpp[word]++;
        }
        return mpp;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mpp1=hash_map_func(s1);
        unordered_map<string,int> mpp2=hash_map_func(s2);
        vector<string> ans;
        auto it1=mpp1.begin(),it2=mpp2.begin();
        while(it1!=mpp1.end()){
            if(it1->second==1 && mpp2.find(it1->first)==mpp2.end()){
               ans.push_back(it1->first);
            }
            ++it1;
        }
        while(it2!=mpp2.end()){
            if(it2->second==1 && mpp1.find(it2->first)==mpp1.end()){
                ans.push_back(it2->first);
            }
            ++it2;
        }
        return ans;
    }
};