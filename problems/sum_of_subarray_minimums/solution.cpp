class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> left(n,-1), right(n,n);
        stack<int> s,s1;
        for (int i = 0; i<n; i++){
            while(!s.empty() && arr[i]< arr[s.top()])  
            {right[s.top()]=i; s.pop();}
            
            s.push(i);
        }
       
        for (int i = n-1; i>=0; i--){
            while(!s1.empty() && arr[i]<= arr[s1.top()])  
            {left[s1.top()]=i; s1.pop();
            }
            
            s1.push(i);
        }       
       
       
        uint64_t ans=0;
        int mod = 1e9+7;
        for (uint64_t i=0; i<n;i++){
            ans = (ans + arr[i] *( (i-left[i]) * (right[i]-i)% mod)) % mod;
            
        }
     
        return ans;
    }
};
/*
3,1,2,4
s - 1 2 4   
R - 1 4 4 4
L - -1 -1 1 2
3 * (1 * 1)  = 3
1 2 3= 6
2 1 2 = 4
4 1 1=4
*/