unordered_map<int, int> mp;
        
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]%k]++;
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            int rem= nums[i]%k;
            
            // case 1 and 2
            if((rem==0 || rem*2==k)) 
                {
                    if (mp[rem]%2!=0)
                        return false;
                    else 
                        continue;
                }
            // case 3
            if( mp[rem]!=mp[k-rem])
                return false;
            
        }
        
        return true;