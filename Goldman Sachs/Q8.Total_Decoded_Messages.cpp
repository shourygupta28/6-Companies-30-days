class Solution {
	public:
		int CountWays(string str){
		    // Code here
		int n= str.length(), mod= 1000000007;
        if (n==0 || str[0]=='0')
            return 0;
        if (n==1)
            return 1;
            
        int count_prev=1, count_prev2=1, count;
        
        for(int i=1; i<n; i++)
        {
            int d= str[i]-'0';
            int dd= (str[i-1]-'0')*10+d;
            
            count=0;
            if(d>0 && d<=9)
                count= (count+count_prev)%mod;
            if(dd>=10 && dd<=26)
                count= (count+count_prev2)%mod;
            
            count_prev2= count_prev%mod;
            count_prev= count%mod;
        }
        
        return count_prev%mod;
		}

};

int main(){
	int t;
	cin >> t;
	while(t--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}