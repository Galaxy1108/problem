/*
### Problem Statement

Takahashi is playing a game. This game has eight worlds, and each world has eight stages. The stages have an order, and the first stage is the $1$st stage in the $1$st world. The next stage after the $j$\-th stage $(1\le j\le 8)$ in the $i$\-th world $(1\le i\le 8)$ is as follows:

-   When $j\lt8$, the next stage is the $(j+1)$\-th stage in the $i$\-th world.
-   When $i\lt8,j=8$, the next stage is the $1$st stage in the $(i+1)$\-th world.
-   When $i=8,j=8$, there is no next stage. This stage is the last stage.

The name of the $j$\-th stage $(1\le j\le 8)$ in the $i$\-th world $(1\le i\le 8)$ is $i$\-$j$. For example, the name of the first stage is `1-1`, and the name of the last stage is `8-8`.

Given the stage name $S$ of the stage Takahashi is currently playing, output the stage name of the next stage.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int i = s[0] - '0';
    int j = s[2] - '0';
    if (j == 8) {
        i++;
        j = 1;
    } else {
        j++;
    }
    cout << i << '-' << j << endl;  
}