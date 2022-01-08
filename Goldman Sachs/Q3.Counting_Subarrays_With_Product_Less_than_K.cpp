class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        if (k < 1) return 0;
        
        long long product=1;
        int l=0, r=0, count=0;
        
        while(l<=r && l<n && r<n)
        {
            product*= a[r];
            
            while( product>=k && l<=r && l<n)
            {
                product/= a[l];
                l++;
            }
            
            count+= r-l+1;
            r++;
        }
        
        return count;
    }
};