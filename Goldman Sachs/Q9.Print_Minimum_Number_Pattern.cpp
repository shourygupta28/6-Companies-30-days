class Solution{   
public:
    string printMinNumberForPattern(string S){
         S+='I';
        int n= S.length();
        stack<char> st;
        int d=1;
        string ans="", res="";
        
        for(int i=0; i<n; i++)
        {
            if(S[i]=='I')
            {
                int num=0;
                if(st.empty())
                    {
                        num=num*10+d;
                        d++;
                    }
                else
                {
                    st.push('X');
                    while(!st.empty())
                    {
                        num=num*10+d;
                        d++;
                        st.pop();
                    }
                }
            ans= to_string(num);
            reverse(ans.begin(), ans.end());
            res+= ans;
            }
            else 
                st.push(S[i]);
        }
        
        return res;
    }
};