class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=0, cur=0, ans = 0;
        for (auto c : bank[0])
            prev += c=='1';
        for (int i=1; i<bank.size(); i++){
            for (auto c : bank[i])
                cur += c=='1';
            if (cur){
                ans += prev * cur;
                prev= cur; cur= 0;
            }
        }
        return ans;
    }
};