class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int b[10000],cnt=10000;
        int n = s.size();
        vector<int> a(n);
        for (int i=0; i<n; i++){
            if (c != s[i]) a[i] = ++cnt;
            else a[i]=cnt=0;
        }
        cnt=10000;
        for (int i=n-1; i>=0; i--){
            if (c != s[i]) b[i] = ++cnt;
            else b[i]=cnt=0;
        }   
        
        for (int i=0; i<n; i++){
            if (b[i]<a[i]) a[i]=b[i];
        }
        return a;
    }
};