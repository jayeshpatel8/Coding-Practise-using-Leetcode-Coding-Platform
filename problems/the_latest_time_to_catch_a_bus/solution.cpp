class Solution {
public:
 int latestTimeCatchTheBus(vector<int>& B, vector<int>& P, int C) {

	sort(begin(B),end(B));
	sort(begin(P),end(P));
	int ans = 0,j =0 ,PN  = P.size(); 
     
    for (auto &i : B){
        int c = 0;
        while ( c < C && j< PN && i >= P[j]){
            if (j==0 ||( P[j] > P[j-1]+1))
                ans = P[j]-1;
            j++;c++;
        }
        if ( c < C && (j == 0 || P[j - 1] != i)) ans = i;
        
    }
     return ans;
 }
 int latestTimeCatchTheBus1(vector<int>& B, vector<int>& P, int C) {

	sort(begin(B),end(B));
	sort(begin(P),end(P));
	int i=0, j =0 ,PN  = P.size(); 
	for (; i<B.size()-1; i++)             //go till N-1 buses
		for (int c = C; j<P.size() && B[i] >= P[j] && c >0 ; c-- ) j++;

	if ( j ==PN)  return B[i];  //  No passenger left  or last BUS is empty so take last BUS

	int c=C;   // simulate last bus
	for (; j<PN && B[i] >= P[j] && c >0 ; c-- ) j++;


	if (j==0 || c > 0 && B[i] != P[j-1])  // /last BUS empty OR last bus not full && P[time] < Last BUS time ==> take last bus
		return B[i];

	for (int k = j-1; k>0; k--){  // BUS is full so try to remove last passanger
		if (P[k] != P[k-1]+1) return P[k]-1;
	}
	return P[0]-1;
  }
};