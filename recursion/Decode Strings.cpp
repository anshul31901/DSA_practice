class Solution {
public:
    bool isDigit (char c){
        return (c>='0'&&c <='9');
    }

    string decode (int &i, string &s){
        int n = s.size();

        string result = "";

        while(i<n && s[i]!=']'){
            if(!isDigit(s[i])){
                result += s[i];
                i++;
            }
            else{
                int k = 0;
                while(isDigit(s[i])){
                    k = k*10 + (s[i]-'0');
                    i++;
                }
                i++;

                string decoded = decode(i,s);

                for(int i = 0 ; i<k ; i++){
                    result += decoded;
                }

            }
        }
        i++;
        return result;

    }

    string decodeString(string s) {
        int i = 0;
        return decode(i,s);   
    }
};
