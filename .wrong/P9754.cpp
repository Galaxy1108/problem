#include <bits/stdc++.h>
using namespace std;

struct struct_t;
struct memory_t;

int type_cnt;

unordered_map<string, int> find_struct;

struct struct_t {
    string name;

    int val_cnt;
    long long width;
    long long max_width;
    int idx;

    vector<int> type;
    vector<string> names;
    vector<long long> start_idx;

    void make_struct(string name_, int val_cnt_, vector<struct_t> type_, vector<string> names_) {
        name = name_;
        val_cnt = val_cnt_;
        width = 0;
        for (int i = 0;i < val_cnt;i++) {
            type.push_back(type_[i].idx);
            max_width = max(max_width, type_[i].max_width);
            while (width % type_[i].width) {
                width++;
            }
            start_idx[i] = width;
            width = width + type_[i].width - 1;
        }
        while (width % max_width) {
            width++;
        }
        names.assign(names_.begin(), names_.end());
        idx = type_cnt++;
        find_struct[name] = idx;
    }

    
};

vector<struct_t> types;

long long get_address(struct_t s, string name_) {
    int idx = name_.find('.');
    string this_name = name_.substr(0, idx);
    string other_name = name_.substr(idx + 1);
    for (int i = 0;i < s.val_cnt;i++) {
        if (s.names[i] == this_name) {
            return s.start_idx[i] + get_address(types[s.type[i]], other_name);
        }
    }
}

struct memory_t {
    vector<struct_t> vals;
    vector<string> names;
    unordered_map<string, int> name_to_idx;

    long long idxs;

    void add_val(struct_t val_, string name_) {
        vals.push_back(val_);
        names.push_back(name_);
        name_to_idx[name_] = vals.size() - 1;
        idxs++;
    }

    int get_address(string name_) {
        int idx = name_.find('.');
        string this_name = name_.substr(0, idx);
        string other_name = name_.substr(idx + 1);
        for (int i = 0;i < idxs;i++) {
            if (names[i] == this_name) {
                return 
            }
        }
    }
};

int main() {
    string s = "a.b.c.d";
    cout << 
}
// -m-1 > -2
// m+1 < 2
// m < 1

// m-1<2
// m < 3

//  -(m+1)/2>=(m-1)/2
// -m-1 >= m-1
// 2m <= 0 
