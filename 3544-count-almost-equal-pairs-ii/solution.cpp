class Solution {
public:
    const int N = 1e7;
    int cnt[10000000]= {};
    int countPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        for (auto i : nums) m[i]++;
        int ans = 0;
        for (auto [i,c] : m){
            ans += cnt[i] * c;
            if (c > 1){
                ans += ( c * (c-1))/2;
            }
            auto s1 = to_string(i);
             int j = s1.size();
            if ( j  < 7) s1 = string( 7-j, '0') + s1;            
            unordered_set<int> n;
            {
                for (int i=0; i<s1.size(); i++){
                    for (int j = i+1; j<s1.size(); j++){
                        swap(s1[i],s1[j]);
                        n.insert(stoi(s1));
                        
                        for (int k = 0; k<s1.size(); k++){
                            for (int l = k+1; l<s1.size(); l++){
                                swap(s1[k],s1[l]);
                                n.insert(stoi(s1));
                                swap(s1[k],s1[l]);    
                            }
                        }
                        swap(s1[i],s1[j]);    
                    }
                }
            }
            for (auto j : n) cnt[j]+=c;
        }
        return ans;
    }
};
