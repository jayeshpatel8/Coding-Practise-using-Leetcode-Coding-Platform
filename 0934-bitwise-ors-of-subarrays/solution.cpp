class Solution {
public:
     int subarrayBitwiseORs(vector<int>& arr) {
        vector<int> set;
        int start=0,end=0;
        for (auto i : arr){
            end=set.size();
            set.push_back(i);
            for (;start<end;start++){
                int n =set[start]|i;
                if (n !=  set.back())set.push_back(n);
            } 
            start = end;
        }
        return unordered_set(begin(set),set.end()).size();
    }
};
