
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

string encode(const string& s)
{
        string result("");
        int count(1);
        result  += s[0];
        for(int i=1;i<s.length();i++)
        {
                if(s[i] == s[i-1])
                {
                        count++;
                }
                else
                {
                        if(count > 1)
                        {
                                string c;
                                stringstream ss;
                                ss<<count;
                                ss>>c;
                                result += c;
                        }
                        result += s[i];
                        count = 1;
                }
        }
        if(count > 1)
        {
                string c;
                stringstream ss;
                ss<<count;
                ss>>c;
                result += c;


        }
        return result;
}

int main()
{
        string s("aaaabbccdd");
        cout<<  encode(s) <<"\n";

        return 0;
}
