class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& po, vector<int>& he, string di) {
        int  N =  po.size();
        vector<int> idx(N), st;
        iota(begin(idx), end(idx),0);

        sort(begin(idx), end(idx), [&](auto a, auto b){ return po[a] < po[b] ;});
        for (auto  i: idx){
            if (di[i]=='L'){
                
                while (!st.empty() && di[st.back()] == 'R'){
                    auto j = st.back();
                    if (he[j] == he[i]){
                        he[i]=0;st.pop_back(); break;
                        
                    }
                    else if (he[j] < he[i]){
                        he[i]--;
                        st.pop_back();
                    }
                    else{
                        he[i]=0;
                        he[j]--;
                        break;
                    }
                }
                    
            }
            if (he[i]!=0) st.push_back(i);
        }
        vector<int> ans;
        sort(begin(st),end(st));
        for (auto i : st){
            ans.push_back(he[i]);
        }
        return ans;
    }
};
