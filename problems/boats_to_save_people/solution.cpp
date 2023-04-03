class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people), end(people));
        int ans=  0, i=0, j=people.size()-1;
        for (; i<=j; j--){
            if (people[i]+people[j]<= limit) i++;
            ans++;
        }
        
        return ans ;
    }
};