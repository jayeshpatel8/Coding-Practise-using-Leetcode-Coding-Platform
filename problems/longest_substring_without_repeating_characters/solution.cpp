class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int A[256]={};
        int start=0,m=0;//"abcabcbb"
        int i=0;
        for (; i<s.size(); i++){
            if (A[s[i]]){
                m = max(m, i-start);
                int c = A[s[i]]-1;
                while(start < c) A[s[start++]]=0;
                start=c+1;
            }
            A[s[i]]=i+1;
        }
        m = max(m, i-start);
        return m;
    }
};