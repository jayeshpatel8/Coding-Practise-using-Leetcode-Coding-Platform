class Solution {
public:
    // state[0] - end with 1 A
    // state[1] - end with P and 0 A
    // state[2] - end with P and 1 A
    // state[3] - end with L and 0 A
    // state[4] - end with L and 1 A
    // state[5] - end with 2L and 0 A
    // state[6] - end with 2L and 1 A
    int checkRecord(int n) {
        vector<size_t> state = {1,1,0,1,0,0,0};    
        int mod= 1e9 + 7;
        for( int i=2; i<=n; i++){
            vector<size_t> next(7);
            next[0] = (state[1] + state[3] + state[5])%mod;
            next[1] = next[0];
            next[2] = (state[0] + state[2] + state[4] + state[6])%mod;
            next[3] = (state[1]);
            next[4] = (state[0] + state[2])%mod;
            next[5] = (state[3]);
            next[6] = ( state[4]);
            swap(state,next) ;
        }
        size_t ans = 0;
        for ( auto i : state)
            ans =(ans + i)%mod;
        return ans;
    }
};
/*
1  2  6
1  3  8 - 1
1  3  8 
*/
