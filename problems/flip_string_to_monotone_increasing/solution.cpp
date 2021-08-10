class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int  i=1,ans=0;
        /*
        int zeros[s.size()], ones[s.size()];
        zeros[0] = s[0]=='0';
        ones[0] = s[0]=='1';
        
        while(i < s.size()){
            ones[i] = ones[i-1] + (s[i]=='1');
            zeros[i++] = min(ones[i-1],zeros[i-1]) + (s[i]=='0');
        }
        */
        int zeros = s[0]=='0', ones  = s[0]=='1';
        while(i < s.size()){
            
            zeros = min(ones,zeros) + (s[i]=='0');
            ones = ones + (s[i]=='1');
            i++;
        }        
        return min(zeros, ones);
    }
};