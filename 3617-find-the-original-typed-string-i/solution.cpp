class Solution {
public:
    int possibleStringCount(string word) {
        int ans=1, prev='A';
        for (auto c : word){
            if (c == prev) ans++;
            else prev=c;
        }

        return ans;
    }
};
