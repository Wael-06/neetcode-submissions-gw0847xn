class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pre=1,size=nums.size(),post=1;
        vector<int>res(size);
        for(int i=0;i<size;i++){
            res[i]=pre;
            pre*=nums[i];
        }
        for(int i=size-1;i>=0;i--){
            res[i]*=post;
            post*=nums[i];
        }

        return res;
    }
};
