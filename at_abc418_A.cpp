/*
 * @Author: Galaxy_1108 int_256t@outlook.com
 * @Date: 2025-08-09 19:43:34
 * @LastEditors: Galaxy_1108 int_256t@outlook.com
 * @LastEditTime: 2025-08-09 20:02:33
 * @FilePath: \problem\at_abc418_A.cpp
 * @Description: 
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    cout << ((n >= 3 && str[n - 3] == 't' && str[n - 2] == 'e' && str[n - 1] == 'a') ? "Yes" : "No");
}