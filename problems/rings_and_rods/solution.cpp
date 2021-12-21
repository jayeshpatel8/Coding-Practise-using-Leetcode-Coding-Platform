class Solution {
public:
    int countPoints(string rings) {
        int cnt[10]={};
        for (int i=0; i<rings.size(); i+=2){
            int c = 0;
            if (rings[i] == 'B') c= 1;
            else if (rings[i] == 'G') c = 2;
            cnt[rings[i+1]-'0'] |= (1<<c);
        }
        int ans=0;
        for ( auto i : cnt) ans +=  i==7;
        return ans;
    }
};