/*
### Problem Statement

There is a triangle ABC with positive area.  
The lengths of the three sides of triangle ABC are $a,b,c$.

Determine whether triangle ABC is isosceles.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b || b == c || a == c) {
        cout << "Yes\n" << endl;
    } else {
        cout << "No\n" << endl;
    }
}