class Solution {
public:
        vector<int> ans;

    vector<int> lexicalOrder(int n) {

        for (int i=1; i<10; i++){            
                dfs(i,n);
        }
        return ans;
    }
    void dfs(int i, int n){
        if (i> n)return;
        ans.push_back(i);
        for (int next =0; next<10; next++){

            int nn = i * 10 + next;
            if (nn <= n) dfs(nn,n);
            else break;
        }
    }
};
