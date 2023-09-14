#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    unordered_map<int, string> mp1;
    unordered_map<string, int> mp2;
    int root;
    cin >> root;
    mp1[root] = "M";
    mp2["M"] = root;
    
    int i = 1;
    while(i<n){
        i++;
        string path;
        int val;
        cin >> path;
        cin >> val;
        
        mp1[val] = path;
        mp2[path] = val;
    }
    
    int val1, val2;
    cin >> val1 >> val2;
    
    string path1 = mp1[val1];
    string path2 = mp1[val2];
    
    string matched="";
    int c1=0, c2=0, len1=path1.length(), len2=path2.length();
    
    while(c1<len1 || c2<len2){
        if(path1[c1]==path2[c2]){
            matched = path1.substr(0, c1+1);           
        }else{
            break;
        }
        c1++;
        c2++;
    }
    
    len1 = path1.length();
    len2 = path2.length();
    
    while(len1 > c1 && path1!="M"){
        path1 = path1.substr(0, len1);
        cout << mp2[path1]  <<" ";
        len1--;
    }
    if(matched==""){
        cout << root;
    }else{
        cout << mp2[matched];
    }
    
    i=c2;
    while(i<len2 && path2!="M"){
        cout << " " << mp2[path2.substr(0, i+1)];
        i++;
    }
    
    return 0;
}