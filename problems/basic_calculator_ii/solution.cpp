class Solution {
public:
    int calculate(string s) {
    s += '+';
        int n=0, N = s.size(), prev = 0, cur = 0, prevSign='+', ans = 0;
        for (int i=0; i<N; i++){
            if (isdigit(s[i]) ){
                while (i < N && isdigit(s[i]))
                    cur = cur * 10 + (s[i++]- '0');
                i--;                
            }
            else if (s[i] == ' ')
                continue;
            else{
                if (prevSign=='+' || prevSign=='-'){
                    ans += prev;
                    prev = prevSign=='+' ? cur : -cur;                    
                }    
                else if (prevSign == '*')
                    prev *= cur;
                else
                    prev /= cur;
                prevSign = s[i];
                cur=0;
            }
        }

        return ans + prev;
    }
};