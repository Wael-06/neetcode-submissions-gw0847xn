class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size);

        int pre = 1;
        for(int i = 0; i < size; i++){
            res[i] = pre;
            pre *= nums[i];
        }

        int post = 1;
        for(int i = size - 1; i >= 0; i--){
            res[i] *= post;
            post *= nums[i];
        }

        return res;
    }
};