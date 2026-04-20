class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>v;
        sort(nums.begin(), nums.end());
        int size=nums.size();
        for(int i=0;i<size;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            int j=i+1,k=size-1,target =-nums[i];
            while(j<k){
                int sum=nums[j]+nums[k];
                if(target>sum)j++;
                else if(target<sum) k--;
                else{v.push_back({nums[i], nums[j], nums[k]});j++;k--; 
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
    return v;}
};
