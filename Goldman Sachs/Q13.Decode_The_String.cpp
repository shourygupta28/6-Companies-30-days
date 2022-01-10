class Solution{
public:
    string decodeString(string &s, int left, int right) {

        int depth = 0, start, end, count = 1;
        string str = "", decoded = "";
        bool push = false, collecting_number = false;

        for(int i = left; i <= right; ++i) {
            char c = s[i];
            
            if(c == '[') {
                if(depth == 0) {
                    start = i+1;
                }
                ++depth;
            }
            else if(c == ']') {
                --depth;
                if(depth == 0) {
                    end = i-1;
                }
            }

            if(depth == 0) {

                if('0' <= c && c <= '9') {
                    while(!collecting_number && count--) decoded += str;
                    if(!collecting_number) count = 0;
                    str = "";
                    count = count * 10 + c - '0';
                    collecting_number = true;
                }
                else {
                    collecting_number = false;
                }

                if(c == ']') {
                    str += decodeString(s, start, end);
                    while(!collecting_number && count--) decoded += str;
                    count = 1;
                    str = "";
                }
                else if('a' <= c && c <= 'z') {
                    str += c;
                }

            }
        }

        while(count--) decoded += str;

        return decoded;

    }
    string decodedString(string s){
        return decodeString(s, 0, s.size() - 1);
    }
};