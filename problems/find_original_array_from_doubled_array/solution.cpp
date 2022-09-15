class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int sz  =changed.size();
        if(sz & 1) return {};
        sort(begin(changed), end(changed));
        int j=sz-1;
        vector<int> ans;
        int freq[100001]={};        
        while(j>=0){
            int i = changed[j], id = i * 2;
            if ( id<= 100001 && freq[id]){ 
                ans.push_back(i);
                freq[id]--;
            }
            else
                freq[i]++;
            j--;
        }
        if (ans.size() * 2 != sz) return {};
        
        return ans;
    }  
    vector<int> findOriginalArray1(vector<int>& changed) {
        vector<int> ans;
        map<int,int> A;
        for (auto  i : changed) A[i]++;
        for (auto it = begin(A); it != end(A); it++){
            if (it->first == 0){
                if (it->second & 1) return {};
                int cnt = it->second/2;
                while (cnt-- > 0) ans.push_back(0);                
            }
            else if (it->second > 0){
                auto it2 = A.lower_bound(it->first * 2);
                if (it2 == end(A) || it2->first > it->first*2 ) {
                    return {};
                }
                int cnt = it->second ,n = it->first;
                it2->second -= cnt;
               
                if (it2->second < 0) return {};
                while (cnt-- > 0) ans.push_back(n);                                
            }
        }
        return ans;
    }
    vector<int> findOriginalArray2(vector<int>& changed) {
        vector<int> ans;
        int f[100001]={};
        for (auto i : changed) f[i]++;
        if (f[0]){
          if (f[0] & 1) return {};
            f[0]/=2;
            while (f[0]-- > 0)
                    ans.push_back(0);
        } 
        for (int i=100000; i>0; i--){
            if (f[i]){
                if (i&1) return {};
                f[i/2] -=f[i];
                if (f[i/2] < 0) return {};                
                while (f[i]-- > 0)
                    ans.push_back(i/2);
            }
        }
        return ans;
    }
};