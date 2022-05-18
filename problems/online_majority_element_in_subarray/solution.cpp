class MajorityChecker {
public:
    unordered_map<int, vector<int>> A;
     vector<int> a;
    MajorityChecker(vector<int>& arr) : a(arr) {
        for (int i=0; i<arr.size(); i++)
            A[arr[i]].push_back(i);
        srand(time(nullptr));
    }
    
    int query(int left, int right, int threshold) {
        
        for (int i =0; i<20; i++){
            auto m = getrandom(left,right);
            if (getfreq(a[m],left,right) >= threshold)
                return a[m];
        }
       
        return -1;
    }
    int getrandom(int l, int r ){
        return random() % (r-l+1)+l;
    }
    int getfreq(int e ,  int l, int r){
        auto v = A.find(e);
        if (v==A.end()) return -1;
        auto &a1 = v->second;
        return upper_bound(begin(a1),end(a1),r)-lower_bound(begin(a1),end(a1),l);
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */