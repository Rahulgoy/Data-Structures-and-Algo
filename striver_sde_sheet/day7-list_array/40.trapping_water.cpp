class Solution {
public:
    int trap(vector<int>& height) {
        int low=0,high=height.size()-1,max_left=0,max_right=0,sum=0;
        while(low<=high){
            if(height[low]<height[high]){
                if(height[low]>max_left) max_left=height[low];
                else sum+=max_left-height[low];
                low++;
            }else{
                if(height[high]>max_right) max_right=height[high];
                else sum+=max_right-height[high];
                high--;
            }
        }
        return sum;
    }
};