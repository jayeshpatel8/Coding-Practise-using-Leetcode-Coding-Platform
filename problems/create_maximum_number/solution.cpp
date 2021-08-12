
class Solution {
public:
    
    unordered_map<uint64_t, int> dp;
    vector<int> ans, temp;
    int N1 ,N2,K;
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        N1 = nums1.size(), N2 = nums2.size(), K=k;
        ans.resize(k,INT_MIN);
        temp.resize(k,INT_MIN);        
        
        for ( int i=max(0,k-N2); i<=min(k,N1); i++){
            vector<int> t1 = getarray(nums1,i); 
            vector<int> t2 = getarray(nums2,k-i);
            merge(t1,i,t2,k-i,temp);
            if(ans < temp)
                ans = temp;            
        }
        return ans;
    }
   vector<int> getarray(vector<int>& nums, int t){
        int sz = nums.size();
        vector<int> ans(t);
        int i=0,r=0;
        while ( t > 0){
            int a = INT_MIN;
            for (int j=i; j<=sz-t; j++){
                if (nums[j]>a) {
                    i=j+1;
                    a=nums[j];
                    ans[r]=a;
                }
            }
            r++,t--;
        }
        return ans;
    }
    void merge(vector<int>& a,int n1,vector<int>& b, int n2,vector<int>& temp){
        int i=0,j=0,t=0;
        while(a.size()&&b.size()){
            if(a > b)
                temp[t++]=a[0], a.erase(a.begin());
            else
                temp[t++]=b[0], b.erase(b.begin());
        }
        while(a.size()) temp[t++]=a[0], a.erase(a.begin());
        while(b.size()) temp[t++]=b[0], b.erase(b.begin());
    }

    void compare(vector<int>& a, vector<int>&b){
        if ( a < b) 
            a=(b);
    }
    void compare(vector<int>& a, vector<int>&b, int k){
        int sza =  a.size(),szb = b.size();
        if (sza == szb){
            if (sza != k) { a = {}; return;}
            if ( a > b) return ;
            else a=(b);
             return;
        } 
        else{
            if(sza == k) return ;
            if(szb == k) a=(b);
            return;
        }
         a={};
        return;
    }
    /*
    vector<int> maxnum(vector<int>& nums1, vector<int>& nums2, int k, int i =0, int j=0){
        if (k==0 || (i>=N1 && j >=N2) || (N1+N2-i-j<k)) 
            return {};
        uint64_t idx  = i | j<<10 | (uint64_t)k << 20 ;
        if (dp.count(idx ) ) return dp[idx];  
        vector<int> ans1,ans2,ans3;
        if (i<N1){
            ans1.push_back(nums1[i]);
            auto n = maxnum(nums1,nums2, k-1,i+1,j);
            ans1.insert(ans1.end(),begin(n),end(n));
        }
        if (j<N2){
            ans2.push_back(nums2[j]);
            auto n = maxnum(nums1,nums2, k-1,i,j+1);
            ans2.insert(ans2.end(),begin(n),end(n));
        }
        compare(ans1,ans2,k);
        ans3 = maxnum(nums1,nums2, k,i+1,j);
        compare(ans1,ans3,k);
        ans3 = maxnum(nums1,nums2, k,i,j+1);
        compare(ans1,ans3,k);        
        
        return dp[idx] = ans1;  
    }    
    */
};