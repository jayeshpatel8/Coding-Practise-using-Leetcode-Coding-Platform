class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if (trees.size() <=3) return trees;
        // find low y
        int ymin  = 0;
        for (int i=1; i< trees.size(); i++)
            if (trees[ymin][1] > trees[i][1] || (trees[ymin][1] == trees[i][1] && trees[ymin][0] > trees[i][0])) ymin = i;
        swap(trees[0],trees[ymin]);
        vector<int> p(trees[0]);
        sort(begin(trees),end(trees),[&](auto &q, auto & r){
            int ccw = orientation(p,q,r);
            if ( ccw == 0)
                return dist(p,r) >= dist(p,q);
            return ccw < 0 ;
            });
        
        // sort the last co=leanear points in descending dist order
        int last = trees.size()-1, i = last-1;
        if (orientation(p,trees[1],trees[last]) != 0){
            while (orientation(p,trees[i],trees[last]) == 0) {
                i--;
            }
            reverse(begin(trees) + i + 1, end(trees));
        }
        
        vector<vector<int>> ans;
        ans.push_back(trees[0]);
        ans.push_back(trees[1]);
        ans.push_back(trees[2]);
        for ( int i=3; i<=last; i++){
            while (orientation(ans[ans.size()-2],ans.back(),trees[i]) > 0)
                ans.pop_back();
            ans.push_back(trees[i]);
        }
        return ans;
    }
    int orientation(vector<int> & p, vector<int>&q, vector<int>&r){
        return ((q[1]-p[1])*(r[0]-q[0]) - (q[0]-p[0])*(r[1]-q[1]));
    }
    int dist(vector<int> & p, vector<int>&q){
        return (q[0]-p[0])*(q[0]-p[0]) +   (q[1]-p[1])*(q[1]-p[1]);
    }
};