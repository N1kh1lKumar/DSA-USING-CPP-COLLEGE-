class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.length();
        int matching_rotations = 0;

       
        for (int i = 0; i < n; ++i) {
            
            string rotated = s.substr(i) + s.substr(0, i);

            
            int score = 0;
            for (int j = 0; j < n - 1; ++j) {
                if (rotated[j] == rotated[j + 1]) {
                    score++;
                }
            }

            // If the score matches k, increment our counter
            if (score == k) {
                matching_rotations++;
            }
        }

        return matching_rotations;
    }
};
