class Solution {
public:
    vector<int> getRow(int idx) {
        if (idx==0) return vector<int>(1,1);
        auto v = getRow(idx-1);
        int i=idx-1;
        while(i>0) {v[i]+=v[i-1];i--;}
        v.push_back(1);
        return v;
    }
};