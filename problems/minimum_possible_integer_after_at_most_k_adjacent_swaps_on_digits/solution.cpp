
class Solution {
    int BIT[30001]={};
    int get(int i){
        int sum=0;
        for (int idx=i; idx > 0; idx -= idx & -idx )
            sum += BIT[idx];
        return sum;
    }
    void update(int i, int n){

        for (int idx=i; idx <= n; idx += idx & -idx )
            BIT[idx] +=1;
    }    
public:
    	string minInteger(string num, int k) {
		if(k <= 0) 
			return num;
		int n = num.size();
		if(k>=n*(n+1)/2){ 
			sort(num.begin(), num.end());
			return num;
		}
        string ans(num);        
        vector<int> unused(n,1);
        priority_queue<int, vector<int>, greater<int>> pq[10];
        for (int i=0; i<n; i++) pq[num[i]-'0'].push(i+1);
        int j=0;
        for (; j<n && k>0; j++){
            for(int i=0; i<10; i++){
                if (pq[i].empty()) continue;
                int idx = pq[i].top();
                int holes = get(idx-1);
                int dist = idx - holes;
                if (dist -1 <= k){
                    k -= (dist - 1);
                    ans[j] = '0' + i;
                    pq[i].pop();
                    update(idx,n);
                    unused[idx-1]=0;
                    break;
                }
            }
        }
        if (j == n) return ans;
        for (int i=0; i<n; i++) 
            if (unused[i]) ans[j++]=num[i];
		return ans;
	}

};