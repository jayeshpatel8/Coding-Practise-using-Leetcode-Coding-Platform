class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> map = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
        
        int ans = 0,N = s.size(),cur =  map[s[0]];
        for (int i=0 ; i<N-1; i++){
            auto  next = map[s[i+1]];
             if ( cur < next)
                 ans -= cur;
            else
                ans += cur;
            cur=next;
        }
        ans += cur;
        return ans;
    }
};