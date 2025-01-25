class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        map<int,int> mpp;
        int i;
        int maxi=candyType.size()/2;
        for(i=0;i<candyType.size();i++){
            mpp[candyType[i]]++;
        }
        int cnt=0;
        for(auto it:mpp){
            cnt++;
        }
        return min(cnt,maxi);
    }
};