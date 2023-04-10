class Solution {
public:
int prime[1000001]={};
    vector<int> closestPrimes(int left, int right) {
        prime[1]=true;
        vector<int> pr, ans(2,-1);
        for (long i=2; i<1000001; i++){
            if (prime[i]) continue;
            pr.push_back(i);
            for (long j=i*i; j<1000001; j+=i){
                prime[j]=true;
            }
        }
        int i=lower_bound(begin(pr),end(pr), left)-begin(pr);
        for (; i+1< pr.size() && pr[i+1] <= right; i++){
            if (ans[0]==-1 || pr[i+1]-pr[i] < ans[1]-ans[0]){
                ans[0]= pr[i],ans[1]=pr[i+1];
            }
        }
        return ans;

    }
};