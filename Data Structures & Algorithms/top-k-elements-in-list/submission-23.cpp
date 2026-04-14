class Solution {
public:

    void fix(vector<int> &res, int i, int k, int x) {
        for (int j = k-1; j > i; j--) {  
            res[j] = res[j - 1];
        }
        res[i] = x;
    }

    void sortRes(vector<int>& res, map<int,int>& mp) {
        sort(res.begin(), res.end(), [&](int a, int b) {
            return mp[a] > mp[b];
        });
    }

    vector<int> topKFrequent(vector<int> &nums, int k) {
        map<int, int> mp;

        for (int n : nums) {
            mp[n]++;
        }

        vector<int> res;

        for (auto &p : mp) {
            int n = p.first;
            int freq = p.second;

            if (res.size() < k) {
                res.push_back(n);
                sortRes(res, mp); // 🔥 key fix
                continue;
            }

            for (int i = 0; i < k; i++) {
                if (freq > mp[res[i]]) {
                    fix(res, i, k, n);
                    sortRes(res, mp); // 🔥 key fix
                    break;
                }
            }
        }

        return res;
    }
};