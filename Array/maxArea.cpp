using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
class Solution{
    public:
    // V_1: time_out 时间复杂度O(n^2)
    int maxArea(vector <int>& height){
        if (height.size() == 1)
            return height[0];
        int area = -1;
        int n = height.size();
        for (int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                area = max((j-i) * min(height[i],height[j]),area);
            }
        }
        return area;
    }
    // 双指针
    int maxArea_V2(vector<int> & height){
        int area = -1; 
        int i = 0 , j = height.size() - 1;
        while(i < j ){
            area = max(area, (j-i)*min(height[i],height[j]));
            if ( height[i] <= height[j])
                i++;
            else 
                j--;
        }
        return area;
    }
};

int main(){
    Solution solution;
    vector<int> height = {4,3,2,1,4};
    cout<<solution.maxArea(height)<<endl;
    return 0 ;
}