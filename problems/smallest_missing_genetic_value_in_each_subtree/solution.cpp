class Solution {
public:
    int label=0, NodeOne=-1;
    vector<int> valToLabel, end;
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int N =  nums.size();
        vector<vector<int>> child(N);
        valToLabel.resize(100002, -1), end.resize(100002, -1);
        for(int i=1; i<N; i++) child[parents[i]].push_back(i);
        preorder(child,0,nums);
        vector<int> ans(N,1);
        if (NodeOne == -1)
            return ans;
      
        
        for (int c = NodeOne,v,label, n =2; c>=0; c = parents[c]){
            while(valToLabel[v = nums[c]] <= (label=valToLabel[n]) && label <= end[v])
                n++;
            ans[c]=n;
        }

        return ans;
    }
    void preorder(vector<vector<int>> &child, int node, vector<int>& nums){  
        int v = nums[node];

        valToLabel[v]=label;
        if (v == 1) NodeOne=node;
        for ( auto c : child[node]){
            label++;
            preorder(child, c, nums);
        }
        end[v] = label;
    }    
};