class Solution {
public:
    int findMin(vector<int> &nums) {
        int res=nums[0],l=0,r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            res=min(res,nums[mid]);
            if(nums[r]>nums[mid]){r=mid-1;}
            else {
                l=mid+1;
            }
        }return res;
    }
};

/*class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return nums[l];
    }
};*/