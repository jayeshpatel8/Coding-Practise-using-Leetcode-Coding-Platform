class Solution {
public:
    int countLargestGroup(int n) {
        int f[37]={};
        for (int i=1; i<=n; i++){
            int s = 0 , j = i;
            while (j >0){
                s += j %10;
                j/=10;
            }

            f[s]++;
        }
        sort(rbegin(f),rend(f));
        int ans = 1;
        for (int i=1; i<36 && f[i] == f[0]; i++ ) ans++;
        return ans;
    }
};
