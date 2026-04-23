class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size=nums.size(),index=-1,l=0,r=size;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>target)r=mid-1;
            else if(nums[mid]<target)l=mid+1;
            else{
                index=mid;
                break;
            }
        }
        return index;
    }
};
