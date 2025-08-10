class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty()){
            string s=q.front().first;
            int len=q.front().second;
            q.pop();

            if(s==endWord) return len;

            for(int i=0;i<s.length();i++){
                string temp=s;
                for(int j=97;j<123;j++){
                    temp[i]=j;
                    if(st.find(temp)!=st.end()){
                        q.push({temp,len+1});
                        st.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};