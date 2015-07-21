class Solution{
public:

	int rob(vector<int> &nums) {
		int len = nums.size();
		int a = nums[0]; // Robbed
		int b = 0; // Not robbed
		for (int i = 1; i < len; ++i) {
			auto ta = b + nums[i];
			auto tb = std::max(a, b);
			a = ta;
			b = tb;
		}
		return std::max(a, b);
	}
};