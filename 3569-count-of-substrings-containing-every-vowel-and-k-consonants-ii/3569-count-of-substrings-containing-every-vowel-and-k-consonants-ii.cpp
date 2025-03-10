class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        return atleast(k,word)-atleast(k+1,word);
    }

    bool isConsonant(char c){
        return (c!='a' && c!='e' && c!='i' && c!='o' && c!='u');
    }

    bool allVowelsPresent(vector<int> &freq){
        return (freq['a'-'a']>0 &&freq['e'-'a']>0 &&freq['i'-'a']>0 &&freq['o'-'a']>0 &&freq['u'-'a']>0); 
    }

    long long atleast(int k, string word){
        int n=word.length();
        vector<int> freq(26);
        long long cnt=0,conso=0;
        int left=0,right;
        for(right=0;right<n;right++){
            if(isConsonant(word[right])) conso++;
            freq[word[right]-'a']++;
            while(conso>=k && allVowelsPresent(freq)){
                cnt+=(n-right);
                if(isConsonant(word[left])) conso--;
                freq[word[left]-'a']--;
                left++;
            }
        }
        return cnt;
    }
};