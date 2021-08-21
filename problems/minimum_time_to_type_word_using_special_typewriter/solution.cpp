class Solution {
public:
    int minTimeToType(string word) {
        int ans=0, prev='a';
        
        for ( auto c : word){
            if (prev <= c)
                ans += min(c - prev, prev - 'a' + 1 + 'z' - c);
            else 
                ans += min( prev - c, c - 'a' + 1 + 'z' - prev);
            ans+=1;
            prev= c;
        }
        cout<< endl;
        return ans;
    }
};