class DetectSquares {
public:
    int freq[1001][1001]={};
    map<int,vector<int>> m;
    DetectSquares() {
        
    }
    
    void add(vector<int> po) {
        
        if (freq[po[0]][po[1]]++) return;
        m[po[0]].push_back( po[1]);
  
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1], ans = 0;
   
        for (auto i : m[x]){
            if (i == y) continue;
            int d =  abs(i - y), x3 = (x - d) ,  x4 = x + d;
            if (x3>=0 && freq[x3][y] && freq[x3][i])                            
                ans += freq[x3][y] * freq[x3][i] * freq[x][i];
         
            if (x4<=1000 && freq[x4][y] && freq[x4][i])
                ans += freq[x4][y] * freq[x4][i] * freq[x][i];  
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */