/*class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res=-1,l=0,r=nums.size(),index=0,least=nums[0];
        while(l<=r){
            int mid=(l+r)/2;
            if(least>nums[mid]){
                least=nums[mid];
                index=mid;
            }
            if(nums[r]>nums[mid]){r=mid-1;}
            else {
                l=mid+1;
            }
        }
        l=0;r=index;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]<target)l=mid+1;
            else r=mid-1;
        }
        l=index;r=nums.size();
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]<target)l=mid+1;
            else r=mid-1;
        }

        return res;
    }
};
*/
//chat's solution:
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) return mid;

            // left half is sorted
            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            // right half is sorted
            else {
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};
