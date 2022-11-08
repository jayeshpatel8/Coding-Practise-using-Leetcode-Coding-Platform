class Solution {
public:
    int maximum69Number (int num) {
        
        int ans = 0 , flag=1;
        if (num >=9666)     ans = 9000, num -=9000;
        else if (num >= 6666)
            ans =9000, flag=0 , num -=6000;     
        if (flag == 0) return ans + num;  

        if (num >=966)     ans += 900, num -=900;
        else if (num >= 666)
            ans +=900, flag=0 , num -=600;
        if (flag == 0) return ans + num;  

        if (num >=96)     ans += 90, num -=90;
        else if (num >= 66)
            ans +=90, flag=0 , num -=60;
        if (flag == 0) return ans + num;  

        if (num >=9)     ans += 9;
        else if (num >= 6)
            ans +=9;

        return ans;
    }

};