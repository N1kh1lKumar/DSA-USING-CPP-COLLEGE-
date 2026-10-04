class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        if(fruits.size() == 1) return max( 1 , fruits[0]);
        
        int start = 0, end = 1, typeCount = 1;
        unordered_map<int, int> freq;

        int maxLength = 0;
        freq[fruits[0]]++;
        for (; end < fruits.size(); end++) {
            freq[fruits[end]]++;

            if (freq[fruits[end]] == 1)
                typeCount++;

            while (typeCount > 2) {
                freq[fruits[start]]--;
                if (freq[fruits[start++]] == 0)
                    typeCount--;
            }

            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};