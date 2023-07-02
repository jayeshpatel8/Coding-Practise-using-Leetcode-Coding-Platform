class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& po, vector<int>& he, string di) {

        vector<int> ids(po.size()),st,ans;
        iota(begin(ids),end(ids),0);
        sort(begin(ids),end(ids),[&](auto a, auto b){
            return po[a] <po[b];});
        
        for (auto i : ids){
            if (di[i]=='L'){

                while (!st.empty() && he[i]){
                    auto &h = he[st.back()];                    
                    if (  h == he[i]) 
                        h=he[i]=0,st.pop_back();
                    else if (  h < he[i]) 
                        h=0, he[i]--,st.pop_back();
                    else  he[i]=0,h--;   
                }
            }
            else 
                st.push_back(i);
        }
        for (auto i : he)
            if (i) ans.push_back(i);
        return ans;
    }
};