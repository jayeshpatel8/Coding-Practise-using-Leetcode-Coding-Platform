class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string a = "ab", b= "ba";
        if (x < y ) swap(a,b), swap(x,y);
        auto ans = 0;
        int c1=0, c2=0;
        
        for (auto c : s){            
            
            if (c == a[0])  c1++;
            else if (c== a[1])
            {
                if ( c1 > 0){
                    c1--;
                    ans +=x;                    
                }
                else c2++;
            }
            else{
                ans += min(c1,c2) * y;
                c1=c2=0;
            }
        }
        ans += min(c1,c2) * y;
        return ans;
    }
};
