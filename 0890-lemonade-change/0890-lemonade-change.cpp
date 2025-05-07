class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives=0,tens=0,twenties=0;
        int n=bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5) fives++;
            else if(bills[i]==10){
                tens++;
                if(fives) fives--;
                else return false;
            }
            else{
                twenties++;
                if(fives && tens){
                    fives--;
                    tens--;
                }
                else if(fives>=3 && !tens){
                    fives-=3;
                }
                else return false;
            }
        }
        return true;
    }
};