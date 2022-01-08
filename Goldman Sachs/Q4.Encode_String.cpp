string encode(string src)
{     
    src+= "$";
    string encoded_src;
    encoded_src= src[0];
    int count=1, n=src.length();
    

    for(int i=1; i<n; i++)
    {
        if(src[i]!=src[i-1])
        {
            encoded_src+= to_string(count);
            
            if(i != n-1)
               encoded_src+= src[i];
               
             count=1;
        }
        else
        {
            count++;
        }
    }
    
    return encoded_src;
}     