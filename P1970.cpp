#include <bits/stdc++.h>
using namespace std;

enum class tag_ec
{
    undefined = -1,
    big = 1,
    small = 0
};

tag_ec tag = tag_ec::undefined;

int main() {
    int n;
    cin >> n;
    int i_this, i_befo;
    cin >> i_befo;
    int anss = 1;
    for (int i = 1; i < n;i++) {
        cin >> i_this;
        if (i_this > i_befo && tag != tag_ec::big) {
            anss++;
            tag = tag_ec::big;
        } else if (i_this < i_befo && tag != tag_ec::small) {
            anss++;
            tag = tag_ec::small;
        }
        i_befo = i_this;
    }
    cout << anss;
}