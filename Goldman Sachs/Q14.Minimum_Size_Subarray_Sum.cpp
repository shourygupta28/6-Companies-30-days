class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
           int l=0, r=0, n=nums.size();
        int res= INT_MAX, curr_sum=0;
        
        while(l<=r && r<n)
        {
            curr_sum+= nums[r];
            
            while(curr_sum>=target)
            {
                res= min(res, r-l+1);
                curr_sum = curr_sum-nums[l];
                l++;
            }
            
            r++;
            
        }
        return res!=INT_MAX ? res: 0;
    }
};
