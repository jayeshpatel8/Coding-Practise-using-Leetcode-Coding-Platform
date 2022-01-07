class OrderedStream {
public:
    vector<string> v;
    int N, i=1;
    OrderedStream(int n) {
        N=n;
        v.resize(n+1,"");
    }
    
    vector<string> insert(int idKey, string value) {
        v[idKey]=value;
        vector<string> ans;
        
        while(i<=N && v[i]!=""){
            ans.push_back(v[i++]);
        }
        
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */