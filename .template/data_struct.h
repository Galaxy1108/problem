#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#include <bits/stdc++.h>
#include "tool.h"
using namespace std;

namespace data_struct {
    /**
     * @brief 范浩强Treap
     * @tparam _T 需要维护的数据类型, 需要支持比较函数
     * @tparam _N 需要的数组长度, 注意没有内存回收
     */
    template<typename _T, idx_t _N>
    struct fhq_treap {
    private:
        /**
         * @brief 范浩强Treap 的节点结构
         */
        struct node {
            idx_t l;        //此节点的左儿子的下标
            idx_t r;        //此节点的右儿子的下标
            int rnd;        //随机值, 按此值形成堆
            int size;       //子树大小
            _T val;         //权值, 按此值形成二叉搜索树
        };
        
        idx_t root = 0;     //根节点下标
        idx_t t_size = 0;   //树的大小
        node tr[_N];        //储存节点的数组, 大小为 _N
        
    public:
        struct iterator;

        idx_t       _newnode        (_T val);
        void        _pushup         (idx_t p);
        void        split           (idx_t p, _T key, idx_t &x, idx_t &y);
        idx_t       merge           (idx_t x, idx_t y);
        iterator    insert          (_T val);
        void        erase           (_T val);
        void        erase_all       (_T val);
        size_t      order_of_key    (_T val);
        iterator    find_by_order   (size_t k);
        iterator    find_by_order   (idx_t p, size_t k);
        iterator    prev            (_T val);
        iterator    next            (_T val);
        iterator    lower_bound     (_T val);
        iterator    upper_bound     (_T val);

        /**
         * @brief 范浩强Treap 的迭代器实现
         */
        struct iterator {
            fhq_treap* treap;   //迭代器绑定的容器
            idx_t idx;          //迭代器对应的节点下标

            iterator(fhq_treap* treap = nullptr, idx_t idx = 0) : treap(treap), idx(idx) {}

            operator    idx_t       () { return idx; }
            _T          operator*   ();
            node*       operator->  ();
            iterator    operator--  ();
            iterator    operator++  ();
            bool        operator==  (iterator& other);
            bool        operator!=  (iterator& other);
        };
    };

    /**
     * @brief 获取迭代器对应节点的值
     */
    template<typename _T, idx_t _N>
    _T fhq_treap<_T, _N>::iterator::operator*() { return treap->tr[idx].val; }

    /**
     * @brief 获取迭代器对应节点
     */
    template<typename _T, idx_t _N>
    typename fhq_treap<_T, _N>::node* fhq_treap<_T, _N>::iterator::operator->() { return &treap->tr[idx]; }

    /**
     * @brief 获取迭代器前驱
     */
    template<typename _T, idx_t _N>
    typename fhq_treap<_T, _N>::iterator fhq_treap<_T, _N>::iterator::operator--() {
        if (idx) {
            idx = treap->prev(treap->tr[idx].val).idx;
        }
        return *this;
    }

    /**
     * @brief 获取迭代器后继
     */
    template<typename _T, idx_t _N>
    typename fhq_treap<_T, _N>::iterator fhq_treap<_T, _N>::iterator::operator++() {
        if (idx) {
            idx = treap->next(treap->tr[idx].val).idx;
        }
        return *this;
    }

    /**
     * @brief 判断迭代器是否相等
     */
    template<typename _T, idx_t _N>
    bool fhq_treap<_T, _N>::iterator::operator==(iterator& other) { return idx == other.idx; }

    /**
     * @brief 判断迭代器是否不等
     */
    template<typename _T, idx_t _N>
    bool fhq_treap<_T, _N>::iterator::operator!=(iterator& other) { return idx != other.idx; }

    /**
     * @brief 在当前 Treap 新建一个节点
     * @param val 新建节点的值
     * @return 节点的下标
     */
    template<typename _T, idx_t _N>
    idx_t fhq_treap<_T, _N>::_newnode(_T val) {
        idx_t new_idx = ++t_size;
        tr[new_idx].val = val;
        tr[new_idx].rnd = rand_gen();
        tr[new_idx].size = 1;
        return new_idx;
    }

    /**
     * @brief 综合左右子树的信息，更新父亲节点
     * @param p 需要更新信息的节点
     */
    template<typename _T, idx_t _N>
    void fhq_treap<_T, _N>::_pushup(idx_t p) {
        if (p) {
            tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + 1;
        }
    }

    /**
     * @brief 按值分裂 Treap
     * @param p 需要分裂的 Treap 的根
     * @param key 分裂的值
     * @param x 左树的根将会存储在这里
     * @param y 右树的根将会存储在这里
     * @details @c p 按值 @c key 分裂成两颗子树：左边的 @c x 和 右边的 @c y ,使得分裂后子树 @c x 中的权值全部不大于 @c key ,子树 @c y 中的权值全部大于 @c key .
     */
    template<typename _T, idx_t _N>
    void fhq_treap<_T, _N>::split(idx_t p, _T key, idx_t &x, idx_t &y) {
        if (!p) {
            x = y = 0;
            return;
        }
        if (tr[p].val <= key) {
            x = p;
            split(tr[p].r, key, tr[p].r, y);
        } else {
            y = p;
            split(tr[p].l, key, x, tr[p].l);
        }
        _pushup(p);
    }

    /**
     * @brief 合并 Treap
     * @param x 需要合并的左树下标
     * @param y 需要合并的右树下标
     * @return 合并后的 Treap 的下标
     * @pre @c x 中全部节点的权值要全部不大于 @c y 中全部节点的权值。
     * @details 按堆的随机值 @c rnd 合并两颗 treap @c x 和 @c y ,使得合并后成为一颗新的 treap
     */
    template<typename _T, idx_t _N>
    idx_t fhq_treap<_T, _N>::merge(idx_t x, idx_t y) {
        if (!x || !y) {
            return x | y;
        }
        if (tr[x].rnd < tr[y].rnd) {
            tr[x].r = merge(tr[x].r, y);
            _pushup(x);
            return x;
        } else {
            tr[y].l = merge(x, tr[y].l);
            _pushup(y);
            return y;
        }
    }

    /**
     * @brief 在当前 Treap 插入值
     * @param val 需要插入的值
     * @return 插入后 @c val 的迭代器
     */
    template<typename _T, idx_t _N>
    typename fhq_treap<_T, _N>::iterator fhq_treap<_T, _N>::insert(_T val) {
        idx_t x, y;
        split(root, val, x, y);
        root = merge(merge(x, _newnode(val)), y);
        return iterator(this, root);
    }

    /**
     * @brief 在当前 Treap 删除一个指定值的节点
     * @param val 需要删除的值
     */
    template<typename _T, idx_t _N>
    void fhq_treap<_T, _N>::erase(_T val) {
        idx_t x, y, z;
        split(root, val, x, z);
        split(x, val - 1, x, y);
        if (y) {
            y = merge(tr[y].l, tr[y].r);
            root = merge(merge(x, y), z);
        } else {
            root = merge(x, z);
        }
    }

    /**
     * @brief 在当前 Treap 删除所有指定值的节点
     * @param val 需要删除的值
     */
    template<typename _T, idx_t _N>
    void fhq_treap<_T, _N>::erase_all(_T val) {
        idx_t x, y, z;
        split(root, val, x, z);
        split(x, val - 1, x, y);
        root = merge(x, z);
    }

    /**
     * @brief 查询指定值的排名
     * @param val 需要查询的值
     */
    template<typename _T, idx_t _N>
    size_t fhq_treap<_T, _N>::order_of_key(_T val) {
        idx_t x, y;
        split(root, val - 1, x, y);
        size_t ans = tr[x].size + 1;
        root = merge(x, y);
        return ans;
    }

    /**
     * @brief 查询指定根内第 @c k 小的节点
     * @param p 给定的根
     * @param k 给定的 @c k
     * @return 指定根内第 @c k 小的节点的迭代器
     */
    template<typename _T, idx_t _N>
    typename fhq_treap<_T, _N>::iterator fhq_treap<_T, _N>::find_by_order(idx_t p, size_t k) {
        while (p) {
            if (tr[tr[p].l].size + 1 == k) {
                return iterator(this, p);
            } else if (tr[tr[p].l].size >= k) {
                p = tr[p].l;
            } else {
                k -= tr[tr[p].l].size + 1;
                p = tr[p].r;
            }
        }
        return iterator(this, 0);
    }
    
    /**
     * @brief 查询当前 Treap 中第 @c k 小的权值
     * @param k 给定的 @c k
     * @return 当前 Treap 第 @c k 小的节点的迭代器
     */
    template<typename _T, idx_t _N>
    typename fhq_treap<_T, _N>::iterator fhq_treap<_T, _N>::find_by_order(size_t k) {
        return find_by_order(root, k);
    }

    /**
     * @brief 找出树中严格小于 @c val 的最接近的节点
     * @param val 给定的数
     * @return 满足要求的数的迭代器
     */
    template<typename _T, idx_t _N>
    typename fhq_treap<_T, _N>::iterator fhq_treap<_T, _N>::prev(_T val) {
        idx_t x, y;
        split(root, val - 1, x, y);
        iterator it = find_by_order(x, tr[x].size);
        root = merge(x, y);
        return it;
    }

    /**
     * @brief 找出树中严格大于 @c val 的最接近的节点
     * @param val 给定的数
     * @return 满足要求的数的迭代器
     */
    template<typename _T, idx_t _N>
    typename fhq_treap<_T, _N>::iterator fhq_treap<_T, _N>::next(_T val) {
        idx_t x, y;
        split(root, val, x, y);
        iterator it = find_by_order(y, 1);
        root = merge(x, y);
        return it;
    }

    /**
     * @brief 找出树中大于等于 @c val 的最接近的节点
     * @param val 给定的数
     * @return 满足要求的数的迭代器
     */
    template<typename _T, idx_t _N>
    typename fhq_treap<_T, _N>::iterator fhq_treap<_T, _N>::lower_bound(_T val) {
        idx_t x, y;
        split(root, val - 1, x, y);
        iterator it = find_by_order(y, 1);
        root = merge(x, y);
        return it;
    }

    /**
     * @brief 找出树中严格大于 @c val 的最接近的节点
     * @param val 给定的数
     * @return 满足要求的数的迭代器
     */
    template<typename _T, idx_t _N>
    typename fhq_treap<_T, _N>::iterator fhq_treap<_T, _N>::upper_bound(_T val) {
        return next(val);
    }


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
        int f = log2(sizes);
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
        int f = log2(r - l + 1);
        return cmp(st[l][f], st[r - (1 << f) + 1][f]);
    }

    /**
     * @brief 分数类
     * @tparam _T 分子和分母类型
     */
    template<typename _T>
    struct frac {
        _T x; // 分子
        _T y; // 分母

        frac(_T x = 0, _T y = 0) : x(x), y(y) {}

        void    operator=   (frac b);
        template<typename _U, typename _U2>     friend  frac<_U>    operator+   (frac<_U> a, frac<_U2> b);
        template<typename _U, typename _U2>     friend  frac<_U>    operator/   (frac<_U> a, _U2 b);
        template<typename _U>                   friend  ostream&    operator<<  (ostream& os, frac<_U> p);
    };

    /**
     * @brief 重载赋值运算符
     * @param b 赋值对象
     */
    template<typename _T>
    void frac<_T>::operator=(frac b) {
        x = b.x;
        y = b.y;
    }

    /**
     * @brief 重载加法运算符
     * @param a 加数
     * @param b 加数
     * @return 和
     */
    template<typename _T, typename _T2>
    frac<_T> operator+(frac<_T> a, frac<_T2> b) {
        if(a.x == 0 && a.y == 0) {
            return b;
        }
        if(b.x == 0 && b.y == 0) {
            return a;
        }
        frac<_T> ans;
        i128 new_y = a.y * b.y;
        i128 new_x = a.x * b.y + b.x * a.y;
        ans.x = new_x;
        ans.y = new_y;
        i128 g = __gcd(ans.x, ans.y);
        ans.x /= g;
        ans.y /= g;
        return ans;
    }

    /**
     * @brief 重载除法运算符
     * @param a 被除数
     * @param b 除数
     * @return 商
     */
    template<typename _T, typename _T2>
    frac<_T> operator/(frac<_T> a, _T2 b) {
        if(a.x == 0 && a.y == 0) {
            return a;
        }
        frac<_T> ans;
        ans.x = a.x;
        ans.y = a.y * b;
        i128 g = __gcd(ans.x, ans.y);
        ans.x /= g;
        ans.y /= g;
        return ans;
    }

    /**
     * @brief 重载输出运算符
     * @param os 输出流
     * @param p 分数
     * @return 输出流
     */
    template<typename _T>
    ostream& operator<<(ostream& os, frac<_T> p) {
        tool::out << p.x << ' ' << p.y;
        return os;
    }
};

#endif