class Solution {
private:
    bool checkEqual(int a[26], int b[26]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        // character count array for s1
        int count1[26] = {0};
        for (char c : s1) {
            count1[c - 'a']++;
        }

        int windowSize = s1.length();
        int count2[26] = {0};
        int i = 0;

        // running for first window
        while (i < windowSize) {
            count2[s2[i] - 'a']++;
            i++;
        }

        if (checkEqual(count1, count2)) return true;

        // sliding window
        while (i < s2.length()) {
            // add new char
            count2[s2[i] - 'a']++;

            // remove old char
            count2[s2[i - windowSize] - 'a']--;

            if (checkEqual(count1, count2)) return true;

            i++;
        }

        return false;
    }
};