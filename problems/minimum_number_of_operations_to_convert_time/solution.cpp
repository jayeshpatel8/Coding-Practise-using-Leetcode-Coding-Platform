class Solution {
public:
    int convertTime(string current, string correct) {
        int curh = (current[0] - '0')* 10 +  (current[1] - '0');
        int corh = (correct[0] - '0')* 10 +  (correct[1] - '0');
        int curm = (current[3] - '0')* 10 +  (current[4] - '0');
        int corm = (correct[3] - '0')* 10 +  (correct[4] - '0');
        int ans = corh  - curh -1;
        
        int diff =  corm +( 60-curm);
        
        if (diff >=60)
            ans += diff/60, diff%=60;
        if (diff >=15)
            ans += diff/15, diff%=15;
       
        if (diff >=5)
            ans += diff/5, diff%=5;
       
        ans += diff;
        
           return ans; 
        
    }
};