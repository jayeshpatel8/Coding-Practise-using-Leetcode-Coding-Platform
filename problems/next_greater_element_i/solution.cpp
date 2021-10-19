class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        st.push(0);
        vector<int> next(nums2.size());
        for (int i=0; i<nums2.size(); i++){         
            while( !st.empty() && nums2[st.top()]  < nums2[i]){
                next[st.top()] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            next[st.top()]=-1; st.pop();
        }
        unordered_map<int,int> s;
        for (int i=0; i<nums1.size(); i++){             
            s[nums1[i]]=i;
        }
        vector<int> ans(nums1.size());
        for (int i=0,j=1; i<nums2.size(); i++){                      
            if (s.count(nums2[i])){                
                ans[s[nums2[i]]]=next[i];
            }            
        }
        return ans;
    }
};