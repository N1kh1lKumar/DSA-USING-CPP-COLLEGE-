class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int start = 0, minLength = INT_MAX;
        unordered_map<int, int> freqMap;

        for (int end = 0; end < cards.size(); end++) {

            freqMap[cards[end]]++;
            while (freqMap[cards[end]] == 2) {
                minLength = min(minLength, end - start + 1);

                freqMap[cards[start]]--;
                start++;
            }
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};
