class Solution {
public:
    int trap(vector<int>& height) {
        int area=0,size=height.size();
        int l=0,r=size-1;
        int maxl=height[l],maxr=height[r];
        while(l<r){
            if(maxl<=maxr){
                l++;
                maxl=max(maxl,height[l]);
                area+=maxl-height[l];
            }else{
                r--;
                maxr=max(maxr,height[r]);
                area+=maxr-height[r];
            }            
        }return area;
    }
};
