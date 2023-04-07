class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        // 1 to toggle to 0: chose nums[i]=1
        // 0 to toggle to 1 : chose nums[j]=1
        // 
        return (s.find('1')==string::npos) == (t.find('1')==string::npos);
        sort(rbegin(s), rend(s));
        sort(rbegin(t), rend(t));

        return (s[0] == t[0]); 

    }
};