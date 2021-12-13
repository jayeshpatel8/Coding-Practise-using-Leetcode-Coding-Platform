class Solution {
public:
    int maxPower(string s) {
        int ans = 1, prev='0',cnt=0;
        for (auto c : s){
            if (prev == c) cnt++;
            else{
                ans = max(ans, cnt);
                cnt=1;prev=c;
            }
        }
        return  max(ans, cnt);
    }
};