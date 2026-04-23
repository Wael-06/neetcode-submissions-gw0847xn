class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);

        for (char c : t) need[c]++;

        int l = 0;
        int formed = 0;
        int required = t.size();

        int minLen = INT_MAX;
        int start = 0;

        for (int r = 0; r < s.size(); r++) {
            need[s[r]]--;

            if (need[s[r]] >= 0)
                formed++;

            while (formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                need[s[l]]++;

                if (need[s[l]] > 0)
                    formed--;

                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};