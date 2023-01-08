class DataStream {
public:
    unordered_map<int,int> m;
    int k,V,cnt=0;
    
    DataStream(int value, int K) {
        k=K,V=value;
    }
    
    bool consec(int num) {
        if (V == num) cnt++;
        else 
        cnt=0;

        return cnt>=k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */