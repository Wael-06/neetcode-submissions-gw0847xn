class Solution {
public:
    int maxArea(vector<int>& height) {
        int size=height.size(),l=0,r=size-1,maxarea=0;
        while(l<r){
            int area =min(height[l],height[r])*(r-l);
            maxarea=max(maxarea,area);
            if(height[r]>=height[l])l++;
            else r--;
        }return maxarea;
    }
};
