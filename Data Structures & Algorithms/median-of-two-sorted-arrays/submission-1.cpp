class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        if (v1.size() > v2.size()) return findMedianSortedArrays(v2, v1);

        int n1 = v1.size(), n2 = v2.size();
        int l = 0, r = n1;

        while (l <= r) {
            int mid1 = (l + r) / 2;
            int mid2 = (n1 + n2 + 1) / 2 - mid1;

            int l1 = (mid1 == 0) ? INT_MIN : v1[mid1 - 1];
            int r1 = (mid1 == n1) ? INT_MAX : v1[mid1];

            int l2 = (mid2 == 0) ? INT_MIN : v2[mid2 - 1];
            int r2 = (mid2 == n2) ? INT_MAX : v2[mid2];

            if (l1 <= r2 && l2 <= r1) {
                if ((n1 + n2) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    return max(l1, l2);
            }
            else if (l1 > r2) {
                r = mid1 - 1;
            }
            else {
                l = mid1 + 1;
            }
        }

        return 0.0;
    }
};

/*
v1.reserve(size);
        v1.insert(v1.end(), v2.begin(), v2.end());
        sort(v1.begin(),v1.end());
        if (size % 2 == 1) {
            return v1[size / 2];
        } else {
            return (v1[size / 2 - 1] + v1[size / 2]) / 2.0;
        }
*/