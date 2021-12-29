class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> ans, n;
        for (int i=m; i>0; i--) n.push_back(i);
        for (  auto i : queries){
            for ( int j=n.size()-1, cnt=0; ; j--){
                if (n[j]==i)
                {ans.push_back(cnt), n[j]=0, n.push_back(i);break;}
                else
                    cnt += n[j] != 0;
            }
        }
        return ans;
    }
};