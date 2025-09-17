#include <bits/stdc++.h>
using namespace std;

#define idx_t unsigned int
#define int long long

int Log2[100005];

/**
 * @brief ST表
 * @tparam _T 需要维护的数据类型
 * @tparam _N 需要的数组长度
 */
template <typename _T, size_t _N>
struct ST {
    _T* arrays;
    _T st[_N][30];
    idx_t sizes;
    _T (*cmp)(_T, _T);
    ST() {};
    ST(_T* _arrays, idx_t _sizes, _T (*_cmp)(_T, _T)) : arrays(_arrays), sizes(_sizes), cmp(_cmp) {}
    void    set         (_T* _arrays, idx_t _sizes, _T (*_cmp)(_T, _T));
    void    set_array   (_T* _arrays);
    void    set_size    (idx_t _sizes);
    void    set_cmp     (_T (*_cmp)(_T, _T));
    void    init        ();
    _T      query       (idx_t l, idx_t r);
};
/**
 * @brief 绑定数组和比较函数
 * @param _arrays 数组
 * @param _sizes 数组长度
 * @param _cmp 比较函数
 */
template <typename _T, size_t _N>
void ST<_T, _N>::set(_T* _arrays, idx_t _sizes, _T (*_cmp)(_T, _T)) {
    arrays = _arrays;
    sizes = _sizes;
    cmp = _cmp;
}
/**
 * @brief 绑定数组
 * @param _arrays 数组
 */
template <typename _T, size_t _N>
void ST<_T, _N>::set_array(_T* _arrays) { arrays = _arrays; }
/**
 * @brief 绑定比较函数
 * @param _cmp 比较函数
 */
template <typename _T, size_t _N>
void ST<_T, _N>::set_cmp(_T (*_cmp)(_T, _T)) { cmp = _cmp; }
/**
 * @brief 绑定数组长度
 * @param _sizes 数组长度
 */
template <typename _T, size_t _N>
void ST<_T, _N>::set_size(idx_t _sizes) { sizes = _sizes; }
/**
 * @brief 初始化 ST 表
 */
template <typename _T, size_t _N>
void ST<_T, _N>::init() {
    for (idx_t i = 1;i <= sizes;i++) {
        st[i][0] = arrays[i];
    }
    int f = Log2[sizes];
    for (idx_t i = 1;i <= f;i++) {
        for (idx_t j = 1;j + (1 << i) <= sizes + 1;j++) {
            st[j][i] = cmp(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
        }
    }
}
/**
 * @brief 查询区间 [l, r] 的最值
 * @param l 区间左端点
 * @param r 区间右端点
 * @return 区间 [l, r] 的最值
 * @pre init() 已被调用
 */
template <typename _T, size_t _N>
_T ST<_T, _N>::query(idx_t l, idx_t r) {
    int f = Log2[r - l + 1];
    return cmp(st[l][f], st[r - (1 << f) + 1][f]);
}

int a[100005], b[100005];
int a0[100005], a1[100005];

ST<int, 100005> st_amin, st_amax, st_bmin, st_bmax, st_a0min, st_a0max;

signed main() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 2; i <= max(n, m); i++) {
        Log2[i] = Log2[i / 2] + 1;
    }
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        if (a[i] >= 0) {
            a0[i] = a[i];
            a1[i] = LLONG_MIN;
        } else {
            a0[i] = LLONG_MAX;
            a1[i] = a[i];
        }
    }
    for (int i = 1;i <= m;i++) {
        cin >> b[i];
    }
    st_amin.set(a, n, [](int a, int b) {
        return (a < b ? a : b);
    });
    st_amax.set(a, n, [](int a, int b) {
        return (a > b ? a : b);
    });
    st_bmin.set(b, m, [](int a, int b) {
        return (a < b ? a : b);
    });
    st_bmax.set(b, m, [](int a, int b) {
        return (a > b ? a : b);
    });
    st_a0max.set(a1, n, [](int a, int b) {
        return (a > b ? a : b);
    });
    st_a0min.set(a0, n, [](int a, int b) {
        return (a < b ? a : b);
    });
    st_amin.init(), st_amax.init(), st_bmin.init(), st_bmax.init(), st_a0min.init(), st_a0max.init();
    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int bmin = st_bmin.query(l2, r2), bmax = st_bmax.query(l2, r2);
        int amax = st_amax.query(l1, r1), amin = st_amin.query(l1, r1);
        int a0max = st_a0max.query(l1, r1), a0min = st_a0min.query(l1, r1);
        int ans = amax * (amax >= 0 ? bmin : bmax);
        ans = max(ans, amin * (amin >= 0 ? bmin : bmax));
        if (a0max != LLONG_MIN) {
            ans = max(ans, a0max * (a0max >= 0 ? bmin : bmax));
        }
        if(a0min != LLONG_MAX) {
            ans = max(ans, a0min * (a0min >= 0 ? bmin : bmax));
        }
        cout << ans << '\n';
    }
}