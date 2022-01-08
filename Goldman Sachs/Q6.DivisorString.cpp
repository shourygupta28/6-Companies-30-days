class Solution {
public:
    string StringDivisor(string str1, string str2) {
        if(str1.length()<str2.length())
            return StringDivisor(str2, str1);
        else if( str1.find(str2)!=0 )
            return "";
        else if( str2=="" )
            return str1;
        else
            return StringDivisor(str1.substr(str2.length()), str2);
    }
};