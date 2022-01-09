class Solution {
  public:
    int findPosition(int N , int M , int K) {
        int ans= (K+M-1)%N;
        if(ans==0)
            return N;
        else
            return ans;
    }
};