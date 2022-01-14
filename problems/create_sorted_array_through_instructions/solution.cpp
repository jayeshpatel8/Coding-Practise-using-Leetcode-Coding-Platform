class Solution {
public:
    int arr[100001]={};
    void add(int i ){
        for (; i < 100001; i += i & -i)
            arr[i]++;
    }
    int get (int i){
        int ans = 0;
        for (; i> 0; i -= i & -i)
            ans += arr[i];        
        return ans;
    }
    int createSortedArray(vector<int>& ins) {
        int ans = 0 ,mod = 1e9 + 7;
        add(ins[0]);
        for (int i=1; i<ins.size(); i++){
            ans = (ans + min(get(ins[i]-1), i - get(ins[i])))%mod; 
            add(ins[i]);
        }
        return ans;
    }
};