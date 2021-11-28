class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> M;
    RangeFreqQuery(vector<int>& arr) {
        for (int i=0; i<arr.size(); i++)
            M[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int v) {
        return upper_bound(begin(M[v]), end(M[v]), right) - lower_bound(begin(M[v]), end(M[v]), left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */