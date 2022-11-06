class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1){sort(begin(s), end(s)); return s;}
        else{
            string ans=s;
            for (int i = 0; i< s.size(); i++){
                auto s2 = s.substr(i)  + s.substr(0,i);
                if (s2 < ans) ans = s2;
            }
            return ans;
        }
    }
};