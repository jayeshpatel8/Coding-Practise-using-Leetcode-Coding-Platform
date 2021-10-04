class Solution {
public:
    int N;
    bool stoneGameIX(vector<int>& stones) {
        vector<int> freq(3);
        N = stones.size();
        for(auto i : stones) freq[i%3]++;
        
        return game(freq,1) || game(freq,2);
    }
    int game(vector<int>  freq, int rem){
        if (freq[rem]  < 1) return false;
        freq[rem]--;
        int sum = rem;
        
        
        for ( int i=1; i<N; i++){
            if (freq[1] && (sum+1)%3 ) sum+=1,freq[1]--;
            else if (freq[2] && (sum+2)%3) sum+=2,freq[2]--;
            else if (freq[0] ) freq[0]--;
            else return i&1;
        }
        return 0;
    }
};