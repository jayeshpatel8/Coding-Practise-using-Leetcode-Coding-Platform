class Solution {
public:
    void reverseString(vector<char>& s) {
        rstr(s,0,s.size()-1);
        return ;
    }
    void rstr(vector<char>& s, int start, int end) {
        if(start>=end) return;
        rstr(s,start+1,end-1);
        swap(s[start],s[end]);
    }
};