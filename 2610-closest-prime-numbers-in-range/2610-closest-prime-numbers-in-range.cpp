class Solution {
public:
    vector<bool> primeVec(int right){
        int i,j;
        vector<bool> prime(right+1,true);
        prime[0]=0,prime[1]=0;
        for(i=2;i*i<=right;i++){
            if(prime[i]){
                for(j=i*i;j<=right;j+=i){
                    prime[j]=false;
                }
            }
        }
        return prime;
    }
    vector<int> closestPrimes(int left, int right) {
        if((right-left<2)) return {-1,-1};
        vector<bool> prime=primeVec(right);
        int i,prev=-1,curr=-1,first=-1,sec=-1;
        int diff=INT_MAX;
        for(i=left;i<=right;i++){
            if(prime[i]){
                if(first==-1){
                    first=i;
                }
                else{
                    sec=i;
                    if((sec-first)<diff){
                        diff=sec-first;
                        prev=first,curr=sec;
                    }
                    first=sec;
                }
            }
        }
        return {prev,curr};
    }
};