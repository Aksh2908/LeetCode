class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i,cntW=0,mini=INT_MAX;
        for(i=0;i<k;i++){
            if(blocks[i]=='W')cntW++;
        }
        int start=0,end=k,n=blocks.length();
        mini=cntW;
        while(end<n){
            if(blocks[start]=='W') cntW--;
            if(blocks[end]=='W') cntW++;
            mini=min(mini,cntW);
            start++;end++;
        }
        return mini;
    }
};