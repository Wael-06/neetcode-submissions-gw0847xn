class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        int size1=v1.size(),size2=v2.size(),size=size1+size2;
        
        v1.reserve(size);
        v1.insert(v1.end(), v2.begin(), v2.end());
        sort(v1.begin(),v1.end());
        if (size % 2 == 1) {
            return v1[size / 2];
        } else {
            return (v1[size / 2 - 1] + v1[size / 2]) / 2.0;
        }
    }
};
