using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
    public:
    // V_1 
    int maxSubArrary(vector<int>&nums){
        int size = nums.size();
        int currentsize[size];
        currentsize[0] = nums[0];
        int ans = nums[0];
        for(int i = 1 ; i < size ; i++){
            currentsize[i] = max(nums[i],(currentsize[i-1]+nums[i]));
            if(currentsize[i] >= ans )
                ans = currentsize[i];
        }
        return ans;
    }
    // V_2  : 滚动数组减少O(n)的空间复杂度
    int maxSubArray_V2(vector<int> & nums){
        int pre = 0; 
        int  maxAns = nums[0];
        for (const auto &x: nums){
            pre = max(pre + x , x);
            maxAns = max(maxAns,pre);
        }
        return maxAns;
    }

};

class Solution_divide{
    public:
    struct Status{
        int lSum,rSum,mSum,iSum;
    };
    Status pushUp(Status l, Status r){
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum,l.iSum+r.lSum);
        int rSum = max(r.rSum,r.iSum+l.rSum);
        int mSum = max(max(l.mSum,r.mSum),l.rSum+r.lSum);
        return (Status){lSum,rSum,mSum,iSum};
    }
    Status get(vector<int>&a , int l , int r){
        if(l == r){
            return (Status){a[l],a[l],a[l],a[l]};
        }
        int m = (l+r)>>1;
        Status lSub = get(a,l,m);
        Status rSub = get(a,m+1,r);
        return pushUp(lSub,rSub);
    }
    int maxSubArray(vector<int>& nums){
        return get(nums,0,nums.size()-1).mSum;
    }
};
int main(){
    Solution solution;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout<< solution.maxSubArrary(nums)<<endl;
    return 0 ;
}