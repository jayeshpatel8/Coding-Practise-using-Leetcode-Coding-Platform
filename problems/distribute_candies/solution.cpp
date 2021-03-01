class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        bitset<200001> types;
        for(auto c : candyType)
            types.set(c+100000);
        return min(types.count(), candyType.size()/2);
    }
};