class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1, j = b.size()-1;
        string s;
        int c = 0;
        while (i>=0 || j>=0){

            int d =  c;
            if (i>=0) d += a[i--]-'0';
            if (j>=0) d += b[j--]-'0' ;
            c = d > 1;
            s.push_back(d & 1 ? '1' : '0');
        }
        if (c) s.push_back('1');
        reverse(begin(s),end(s));
        return s;
    }
};