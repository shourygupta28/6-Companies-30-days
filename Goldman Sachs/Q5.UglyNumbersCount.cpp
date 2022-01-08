class Solution{
public:	
	ull getNthUglyNo(int n) {
	    ull ugly[n+1];
	    ugly[1]=1;
	    
	    ull ix2=1, ix3=1, ix5=1, count=2;
	    
	    while(count<=n)
	    {
	        ull val2= ugly[ix2]*2, val3= ugly[ix3]*3, val5= ugly[ix5]*5;
	        ull val= min(val2, min(val3, val5));
	        ugly[count]= val;
	        count++;
	        if(val==val2) ix2++;
	        if(val==val3) ix3++;
	        if(val==val5) ix5++;
	    }
	    
	    return ugly[n];
	}
};