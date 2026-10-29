class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> seen;
        int strength = 0;

        for (char ch : password) {
            if (seen.count(ch))
                continue;

            seen.insert(ch);

            if (islower(ch))
                strength += 1;
            else if (isupper(ch))
                strength += 2;
            else if (isdigit(ch))
                strength += 3;
            else if (ch == '!' || ch == '@' || ch == '#' || ch == '$')
                strength += 5;
        }

        return strength;
    }
};
