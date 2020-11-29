class Solution {
public:
    int candy(vector<int>& rate) {
        int n = rate.size();
        vector<int> CandyL(n,0);
        vector<int> CandyR(n,0);
        
        for (int i=1; i<n; i++){
            if (rate[i] > rate [i-1])
                CandyL[i]=CandyL[i-1]+1;
        }
        int sum=max(CandyR[n-1], CandyL[n-1]);
        for (int i=n-2 ; i >=0; i--){
            if (rate[i] > rate [i+1])
                CandyR[i]= CandyR[i+1]+1;
            sum +=max(CandyR[i], CandyL[i]);
        }                
        return sum+n;
    }
};