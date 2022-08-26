#include <bits/stdc++.h>
using namespace std;

vector<int> Kmp(string &str)
{
    int n = str.size();
    vector<int> lps(n, 0);
    // cout<<str<<endl;

    int len = 0, i = 1;
    while (i < n)
    {
        
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            // cout<<lps[i-1]<<endl;
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i]=0;
                i++;
            }
                
        }
        // cout<<i<<" "<<len<<endl;
        
    }
    return lps;
}
int main()
{
    string str, p;
    cin >> str;
    cin >> p;
    str = p + '$' + str;

    vector<int> lps = Kmp(str);
    int ans = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (lps[i] == p.size())
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}