class Solution {
public:
    int countTime(string time) {
        int h1= time[0] == '?' ? -1 : time[0]-'0', h2= time[1] ==  '?' ? -1 : time[1]-'0';
        int ans=  1;
        if (h1<0 || h2<0){
            
            if (h1 <0 && h2<0) ans = 24;
            else if ( h1<0){
                ans = 2 + (h2<4);
            }
            else{
                ans = h1==2 ? 4 : 10;
            }
        }
        
    int m1= time[3] ==  '?' ? -1 : time[3]-'0', m2= time[4] == '?' ? -1 : time[4]-'0';
        
        if (m1<0 || m2<0){
       
            if (m1 <0 && m2<0) ans *= 60;
            else if ( m1<0){
                ans *= 6;
            }
            else{
                ans *= 10;
            }
        }        
        return ans;
    }
};