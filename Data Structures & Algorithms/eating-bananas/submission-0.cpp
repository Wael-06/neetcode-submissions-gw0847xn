class Solution {
public:
    bool canFinish(vector<int>& piles, int k, int h) {
        int total = 0;
        for (int p : piles) {
            total += (p + k - 1) / k;
        }
        return total <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (canFinish(piles, mid, h)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};