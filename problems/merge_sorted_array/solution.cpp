class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        map<int,int> map;
        
        for (int i=0; i<m;i++) map[nums1[i]]++;
        for (auto i:nums2) map[i]++;   
        int c=0;
        for (auto i = map.begin(); i!= map.end();i++)
        {
            while(i->second--)
                nums1[c++]=i->first;   
        }
    }
};