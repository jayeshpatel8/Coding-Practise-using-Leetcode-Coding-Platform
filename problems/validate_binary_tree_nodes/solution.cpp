class Solution {
public:
    bool vis[10001]={0};
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        vector<int> v1(n+1);
        for (int i =0; i<n; i++){    
            if (l[i] !=  -1)
                v1[l[i]]++;
            if (r[i] !=  -1)
                v1[r[i]]++;
            
        }
        
        if (*min_element(begin(v1),end(v1)) >=1 || *max_element(begin(v1),end(v1)) >=2) return false;
        int m = -1;
        for (int i =0; i<n; i++){            
            if (v1[i]==0){
                if (m !=-1) return false;
                m = i;
            }
        }
         dfs(l,r,m);
        for (int i =0; i<n; i++){
            if (vis[i] == 0) return false;
        }
        return true;
    }
    bool dfs(vector<int>& l, vector<int>& r, int i ){
        if (i == -1) return true;
        if (vis[i]) return false;
        vis[i]=1;
        return (dfs(l,r,l[i])  && dfs(l,r,r[i]) );
    }
};