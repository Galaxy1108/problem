#ifndef TOOL_H
#define TOOL_H

#include <bits/stdc++.h>
using namespace std;

//自定义的 rand 函数, 基于 mt19937
mt19937 rand_gen(chrono::high_resolution_clock::now().time_since_epoch().count());
//用来表示下标的数据类型, 基于 unsigned int
using idx_t = unsigned int;
using i32   = int;          //int 的别名
using i64   = long long;    //long long 的别名
using i128 = __int128;     //__int128 的别名

namespace tool {
    /**
     * @brief 输出流类, 用于输出数据
     */
    struct t_ostream {
        /**
        * @brief 输出 _T 类型的数据
        * @param os 输出流
        * @param data 要输出的数据
        * @return 输出流
        */
        template<typename _T>
        t_ostream& operator<<  (_T data) {
            cout << data;
            return *this;
        }
    }out;

    /**
     * @brief 输出 i128 类型的数据
     * @param os 输出流
     * @param data 要输出的数据
     * @return 输出流
     */
    t_ostream& operator<<(t_ostream& os, i128 data) {
        if (data < 0) {
            putchar('-');
            data = -data;
        }
        if (data == 0) {
            putchar('0');
            return os;
        }
        int len = 0;
        char buf[50];
        while (data) {
            buf[len++] = data % 10 + '0';
            data /= 10;
        }
        while (len--) {
            putchar(buf[len]);
        }
        return os;
    }
};

#endif