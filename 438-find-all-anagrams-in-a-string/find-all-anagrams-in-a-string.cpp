class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> indices;

        if (p.size() > s.size())
            return indices;

        array<int, 26> freqOfP{};
        array<int, 26> freqOfWindow{};

        for (char ch : p) {
            freqOfP[ch - 'a']++;
        }

        int start = 0;

        for (int end = 0; end < s.size(); end++) {
            freqOfWindow[s[end] - 'a']++;

            if (end - start + 1 == p.size()) {

                if (freqOfWindow == freqOfP) {
                    indices.push_back(start);
                }

                freqOfWindow[s[start] - 'a']--;
                start++;
            }
        }

        return indices;
    }
};
