class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int sz = a+b+c, acnt=0,bcnt=0,ccnt=0;
        string ans;
        for (int i=0; i<sz; i++){
            if ((a >= b && a>=c && acnt != 2) || ((bcnt==2 || ccnt==2) && a>0))            
                ans +='a', acnt++, bcnt=ccnt=0,a--;
            else if ((b >= a && b>=c && bcnt != 2) || ((acnt==2 || ccnt==2) && b>0))            
                ans +='b', bcnt++, acnt=ccnt=0,b--;
            else if ((c >= b && c>=a && ccnt != 2) || ((bcnt==2 || acnt==2) && c>0))            
                ans +='c', ccnt++, bcnt=acnt=0,c--;  
            else
                return ans;
        }
        return ans;
    }
};