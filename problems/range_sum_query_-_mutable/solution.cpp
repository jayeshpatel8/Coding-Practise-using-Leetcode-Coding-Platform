class NumArray {
public:
    vector<int> bt,num;
        int n;
    //int num[101];
    NumArray(vector<int>& nums) {
        n=nums.size()+1;
        bt.resize(n,0);
        num.resize(n,0);
        
        for (int i=0; i<nums.size();i++){ update(i,nums[i]);
                                         
                                        }
        
    }
    
    void update(int index, int val) {
        //index ++;
        int nval = val -num[index];
        num[index]=val;
        for (int i=++index; i<n; i+=i & -i){
            bt[i] += nval; 
        }
    }
    int pointsum(int i){
        int sum=0;
        i++;
        for (; i>0;i -=i & -i) sum +=bt[i];
        return sum;
    }
    int sumRange(int l, int r) {
     
        return pointsum(r) - pointsum(l-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */