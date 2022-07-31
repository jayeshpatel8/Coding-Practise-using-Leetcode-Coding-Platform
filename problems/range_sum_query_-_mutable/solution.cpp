class NumArray {
public:
    static constexpr int N = 30001;
    int BIT[N]={};
    void add(int i, int val){
        for (;i<N;i+= i & -i){
            BIT[i]+=val;
        }
    }
    int get(int i){
        int sum=0;
        for (; i>0; i-= i & -i)
            sum += BIT[i];
        return sum;
    }
    int v[N]={};
    NumArray(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++)
            v[i] = nums[i], add(i+1,nums[i]);
    }
    
    void update(int i, int val) {
        add(i+1,val - v[i]);
        v[i] =val;
    }
    
    int sumRange(int left, int right) {        
        return get(right+1) - get(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */