class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        if(k>n) return 0;
        int i,j,cnt=0;
        bool isAlternating=true;
        for (i=0;i<k-1;i++) {
            if (colors[i] == colors[i + 1]) {
                isAlternating = false;
                break;
            }
        }
        if(isAlternating) cnt++;
        for(j=1;j<n;j++){
            if (colors[j-1] == colors[j] || colors[(j+k-2)%n] == colors[(j+k-1)%n]) isAlternating = false;
            if(isAlternating) cnt++;
            else{
                isAlternating=true;
                for(i=0;i<k-1;i++){
                    if(colors[(j+i)%n]==colors[(j+i+1)%n]){
                        isAlternating=false;
                        break;
                    }
                }
                if(isAlternating) cnt++;
            }
        }
        return cnt;
    }
};