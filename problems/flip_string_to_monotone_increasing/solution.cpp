class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int  i=0,ans=0;

        int zeros = 0, ones  = 0;
        while(i < s.size()){
            
            zeros = min(ones,zeros) + (s[i]=='0');
            ones = ones + (s[i]=='1');
            i++;
        }        
        return min(zeros, ones);
    }
};