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
    int subarrayBitwiseORs2(vector<int>& arr) {
        unordered_set<int> cur,prev,ans;
        int start=0, end=0;
        for (auto i : arr){
            cur={i};
            cur.insert(i);
            for (auto j : prev)cur.insert(j|i);
            
            for (auto i : prev = cur) ans.insert(i);            
        }
        return ans.size();
    }
};
/*
    fn(i=0){
        if (i>=n) return 0;
        
    }

*/