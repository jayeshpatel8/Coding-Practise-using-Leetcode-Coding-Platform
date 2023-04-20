class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = 100,cnt = 0;
        for (int i=0 ,  j=0; i < blocks.size(); i++){
            cnt += blocks[i] =='W';
            if ( i>=k-1 ){
                ans= min(ans, cnt);
                  cnt -= blocks[j++]=='W';
            }
        }     
        return ans;
    }
};