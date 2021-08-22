class Solution {
public:
    int minTimeToType(string word) {
        int ans=word.size(), prev='a';
        
        for ( auto &c : word){
            int diff = abs(c-prev);
            ans += min(diff, 26 - diff);
            prev= c;
        }
        return ans;
    }
};