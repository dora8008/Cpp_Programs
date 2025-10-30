class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int L = maxNum == 0 ? 1 : 32 - __builtin_clz(maxNum);  // Safe handling for 0
        int maxXor = 0, mask = 0;
        unordered_set<int> prefixes;

        for (int i = L - 1; i >= 0; i--) {
            mask |= (1 << i);
            prefixes.clear();
            for (int num : nums) prefixes.insert(num & mask);
            int candidate = maxXor | (1 << i);
            for (int prefix : prefixes) {
                if (prefixes.count(prefix ^ candidate)) {
                    maxXor = candidate;
                    break;
                }
            }
        }
        return maxXor;
    }
};
