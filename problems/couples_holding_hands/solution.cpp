class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> map(n);
        for (int i=0; i<n;i++){
            map[row[i]]=i;
        }
        int ans=0;
        for (int i=0; i<n;i+=2){
            int a = row[i],b=row[i+1];
            if (a/2 == b/2) continue;
            ans++;
            int idx = map[a + (a%2 ? -1 : 1)];
            row[idx]=b;
            map[b]=idx;                
        }
        return ans;
    }
};