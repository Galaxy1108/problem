#include <bits/stdc++.h>
using namespace std;

template <long long _SIZE>
struct trie_node {
    long long a[_SIZE];
    long long this_ver;
    bool is_end;
};

template <long long _SIZE, long long _LENS, char _PREL>
struct trie {
    trie_node<_SIZE> nodes[_LENS];
    long long tops = 0;
    long long add_node(long long ver) {
        nodes[++tops].this_ver = ver;
        return tops;
    }
    void add_string(string str) {
        long long its_node = 0, ver;
        for (auto its : str) {
            ver = its - _PREL;
            if (!nodes[its_node].a[ver]) {
                nodes[its_node].a[ver] = add_node(ver);
            }
            its_node = nodes[its_node].a[ver];
        }
        nodes[its_node].is_end = true;
    }
    void make_fail() {

    }
};

int main() {
    long long n;
    cin >> n;
    string str;
    for (long long i = 0; i < n;i++) {
        cin >> str[i];
    }
}