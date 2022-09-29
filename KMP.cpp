// KMP
#include <bits/stdc++.h>
using namespace std;
#define ll long long int


// prefix function  -- LPS
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> p(n);p[0]=0;
    for (int i = 1; i < n; i++) {
        int j = p[i-1];
        while (j > 0 && s[i] != s[j])
            j = p[j-1];
        if (s[i] == s[j])j++;
        p[i] = j;
    }
    return p;
}
bool KMP(string text, string pattern){
    vector<int> lps = prefix_function(pattern);
    int i=0,j=0;
    while(i < text.size() && j < pattern.size()){
        if(text[i] == pattern[j]){
            i++;j++;
        }else{
            if(j!=0)j = lps[j-1];
            else i++;
        }
    }
    if(j == pattern.size())return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
       
       string a="abcdef",b="abcdcd";
       KMP(a,b);
    
}