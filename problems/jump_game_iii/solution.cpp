class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (!arr[start]) return true;
        queue<int> q;
        q.push(start);
        int N = arr.size();
        vector<bool> vis(N,false);
        
        while(!q.empty()){
            int i = q.front(); q.pop();
            if (arr[i] == 0) return true;
            
            vis[i]=true;
            int j = i + arr[i];
            if (j <N && !vis[j]) 
                q.push(j);
            j = i - arr[i];
            if (j >=0 && !vis[j]) 
                q.push(j);
        }
        return false;
    }
};