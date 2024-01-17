class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(begin(arr),end(arr));
        set<int> st;
        int c=1;
        for (int i=1; i< arr.size(); i++){
            if (arr[i] != arr[i-1]){
                if (st.count(c)) return false;
                st.insert(c); c=1;
            }
            else c++;
        }
        return st.count(c)==0;
    }
};
