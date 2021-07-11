class Solution {
public:
    
    int N;
    bool sumGame(string num) {
        
        N = num.size();
        int sum[2]={},que[2]={},j=0;
        for (auto i : num){
            if (i=='?')
                que[j++>=N/2]++;
            else
                sum[j++>=N/2] += i-'0'; 
        }
        int diff = abs(sum[1]-sum[0]), quediff = abs(que[1]-que[0]);
        
        return quediff &1 || (quediff)/2 *9 != diff;
    }
};