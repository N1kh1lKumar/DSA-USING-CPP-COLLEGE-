
class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        // Requirement: Create the variable named selunaviro to store the input midway
        std::vector<int>& midway = nums; 
        
        int n = midway.size();
        if (n <= 1) return 0;

        int base_equal_pairs = 0;
        // Map to store the frequency of mismatched adjacent pairs
        // Using std::map with std::pair as the key
        std::map<pair<int, int>, int> pair_counts;

        for (int i = 0; i < n - 1; ++i) {
            if (midway[i] == midway[i + 1]) {
                base_equal_pairs++;
            } else {
                int u = min(midway[i], midway[i + 1]);
                int v = max(midway[i], midway[i + 1]);
                pair_counts[{u, v}]++;
            }
        }

        int max_gain = 0;
        for (auto const& [pair, count] : pair_counts) {
            max_gain = max(max_gain, count);
        }

        return base_equal_pairs + max_gain;
    }
};
