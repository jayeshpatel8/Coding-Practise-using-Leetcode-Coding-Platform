class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        vector<int> pos(100001),neg(pos);
        int j = 100001;
        for (auto i : arr){
            if (i<0)
                neg[i = abs(i)]++;
            else
                pos[(i)]++;
            if (j>i)  j = i;
        } 
        if (pos[0]%2) return false;
        for (int i=j; i<100001/2;i++){
            if (neg[i*2] < neg[i] || pos[i*2] < pos[i]) 
                return false;
            
            pos[i*2] -= pos[i];
            neg[i*2] -= neg[i];    

        }
        for (int i = 100001/2 ; i<100001; i++)
            if (pos[i] || neg[i]) return false;
        return true;
/*
        unordered_map<int,int> m;
        for(auto a : arr) m[a]++;
        vector<int> keys;
        for(auto it = m.begin(); it != m.end(); it++) {
            keys.push_back(it->first);
        }
        sort(keys.begin(), keys.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
        for(int i = 0; i < keys.size(); i++) {
            int key = keys[i], target = 2 * key;
            if (m[target] < m[key]) return false;
            m[target] -= m[key];
        }
        return true;
 */       
            
        /*
        unordered_map<int,int> M;
        sort(begin(arr),end(arr));

        for (int j = 0; j<arr.size(); j++){
            int i = arr[j];
            if (i < 0 && M.count((long)i*2)){
                if (M[i*2] == 1) M.erase(i*2);
                else M[i*2]--;
            }
            else if (i >= 0 && i%2 == 0 && M.count(i/2)){
                if (M[i/2] == 1) M.erase(i/2);
                else M[i/2]--;
            }            
            else{
                M[i]++;
            }
        }
       
        return M.empty();
        */
    }
};

// [-1,4,6,8,-4,6,-6,3,-2,3,-3,-8]
//  -8 , -6, -4, -3, -2, -1 ,3, 3,4,6,6,8 