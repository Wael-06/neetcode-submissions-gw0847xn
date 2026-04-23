/*class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=0,maxnum=0,previndex=0,secondmax=0,secondindex=0,size=nums.size();
        vector<int>res(size-k+1);
        while(l<(size-k+1)){
            if(previndex>=l&&previndex<=l+k){
                if(maxnum<nums[l+k]){
                    previndex=l+k;
                    maxnum=nums[l+k];
                    res[l++]=maxnum;
                }
            }
                else{
                    maxnum=nums[l];
                    previndex=l;
                    for(int i=l+1;i<k+l;i++){
                    if(nums[i]>maxnum){
                        maxnum=nums[i];
                        previndex=i;
                    }
                    }res[l++]=maxnum;
                }
            
        }return res;
    }
};*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;

        int maxnum = 0;
        int previndex = -1;

        for (int l = 0; l <= n - k; l++) {

            // if previous max is still inside window
            if (previndex >= l && previndex < l + k) {
                int newIndex = l + k - 1;

                if (nums[newIndex] > maxnum) {
                    maxnum = nums[newIndex];
                    previndex = newIndex;
                }
            } else {
                // recompute max
                maxnum = nums[l];
                previndex = l;

                for (int i = l + 1; i < l + k; i++) {
                    if (nums[i] > maxnum) {
                        maxnum = nums[i];
                        previndex = i;
                    }
                }
            }

            res.push_back(maxnum);
        }

        return res;
    }
};
