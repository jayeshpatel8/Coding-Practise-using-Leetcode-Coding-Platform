class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        
        for (int i= energy.size()-1-k; i>=0; i--){
            energy[i] +=energy[i+k];
        }
        return *max_element(begin(energy), end(energy));
    }
};
