 using ll = unsigned long long;
class Solution {
public:
    vector<int> prime;
    ll gcd1(ll a, ll b){
       while (a > 0 && b > 0) {
            if (a > b) {
                a = a % b;
            }
            else {
                b = b % a;
            }
        }
        if (a == 0) {
            return b;
        }
        return a;
    }
    unordered_set<int> getnum(ll a , unordered_set<int> &st){
        ll b=1;
        //unordered_set<int> st; 
        for (auto di : prime)      
        {
            if (a >= di && (a % di == 0)) st.insert(di);
            while (a >= di && (a % di == 0)) a /=di;  
            if (a < di) break;
        }
        if (a> 1)
        st.insert(a);
        return st;
    }
    
    int findValidSplit(vector<int>& nums) {
               int possible =0;
        int n = nums.size();
        for(int i=0;i<=possible;i++){
            int ele = nums[i];
            for(int j=i+1;j<n;j++){
                if(nums[j]%ele==0) possible = max(possible,j);
                if(ele%nums[j]==0) possible = max(possible,j);
            }
        }
        return possible<=(n-2)?possible:-1;
        vector<unordered_set<int> > pro(nums.size());
        int max_e = *max_element(begin(nums), end(nums));
        vector<int> no_pr(max_e+1,0) ;
        
        for (int i=2; i*i<=max_e; i++){
            for (int j=i+i; j<=max_e; j+=i)
                no_pr[j]=1;
        }
        for (int i=2; i<=max_e; i++) 
            if (no_pr[i]==0) prime.push_back(i);
       
        
        unordered_set<int> p ,p1;
        for (int i=nums.size()-1; i>=0; i--){
            getnum(nums[i],p);            
            pro[i] = p;
        }
        //ll p1=1;
        for (int i=0; i<nums.size()-1; i++){
             getnum(nums[i],p1);
            //for (auto s : st) p1.insert(s); 
            //unordered_map<int,int>m;
            //for (auto i : p1) m[i]++;
            //for (auto j : pro[i+1]) m[j]++;
            int f=0;
            for (auto j : p1)
            {
                if ( pro[i+1].count(j)) {
                    f=1;
                    break;
                }
            }
            if (f==0)  {
                return i;
            }
        }
        
        return -1;
    }
};