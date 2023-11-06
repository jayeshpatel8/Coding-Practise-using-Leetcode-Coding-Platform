class SeatManager {
public:
set<int> s;
int c = 0;
SeatManager(int n) {
	
}
int reserve() {
	if (s.empty()) return ++c;
	auto ans = *begin(s); s.erase(begin(s));
	return ans;
}
void unreserve(int seatNumber) {
	s.insert(seatNumber);
}
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */