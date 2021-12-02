//
// Created by red-dandelions on 2021/11/24.
//
/**
 * 这个头文件实现了：
 * reverse_iterator         反向迭代器
 * back_insert_iterator     后插迭代器
 * front_insert_iterator    前插迭代器
 * normal_iterator          普通迭代器
 * move_iterator            移动迭代器
 */
#ifndef STL_STL_ITERATOR_H
#define STL_STL_ITERATOR_H

#include "stl_iterator_base.h"

namespace mystl {
    /**
     * reverse_iterator类的实现
     * reverse_iterator迭代器，继承iterator类
     * 支持*和->运算符操作
     * 支持后++和前++，后--和前--， 以及各种运算符，比较符。
     */
    template<typename _Iterator>
    class reverse_iterator
            : public iterator<typename iterator_traits<_Iterator>::iterator_category,
                    typename iterator_traits<_Iterator>::value_type,
                    typename iterator_traits<_Iterator>::difference_type,
                    typename iterator_traits<_Iterator>::pointer,
                    typename iterator_traits<_Iterator>::reference> {
    protected:
        _Iterator current;
        typedef iterator_traits<_Iterator> __traits_type;

    public:
        typedef _Iterator                               iterator_type;
        typedef typename __traits_type::difference_type difference_type;
        typedef typename __traits_type::pointer         pointer;
        typedef typename __traits_type::reference       reference;

        //各种构造函数
        reverse_iterator() : current() {}

        explicit reverse_iterator(iterator_type _x) : current(_x) {}

        reverse_iterator(const reverse_iterator &_x) : current(_x.current) {}

        template<typename _Iterator1>
        reverse_iterator(const reverse_iterator<_Iterator1> &_x)
                : current(_x.base()) {}

        iterator_type
        base() const { return current; }

        //*、->、++、--、+、+=、-、-=、[]操作的实现
        reference
        operator*() const {
            _Iterator _tmp = current;
            return *--_tmp;
        }

        pointer
        operator->() const { return &(operator*()); }

        reverse_iterator &
        operator++() {
            --current;
            return *this;
        }

        reverse_iterator &
        operator++(int) {
            reverse_iterator _tmp = *this;
            --current;
            return _tmp;
        }

        reverse_iterator &
        operator--() {
            ++current;
            return *this;
        }

        reverse_iterator &
        operator--(int) {
            reverse_iterator _tmp = *this;
            ++current;
            return _tmp;
        }

        reverse_iterator
        operator+(difference_type _n) const { return reverse_iterator(current - _n); }

        reverse_iterator &
        operator+=(difference_type _n) {
            current -= _n;
            return *this;
        }

        reverse_iterator
        operator-(difference_type _n) const { return reverse_iterator(current + _n); }

        reverse_iterator &
        operator-=(difference_type _n) {
            current += _n;
            return *this;
        }

        reference
        operator[](difference_type _n) const { return *(*this + _n); }
    };

    /**
     * reverse_iterator类各种比较运算符的实现
     */
    template<typename _Iterator>
    inline bool
    operator==(const reverse_iterator<_Iterator> &_x,
               const reverse_iterator<_Iterator> &_y) { return _x.base() == _y.base(); }

    template<typename _Iterator>
    inline bool
    operator<(const reverse_iterator<_Iterator> &_x,
              const reverse_iterator<_Iterator> &_y) {
        return _y.base() < _x.base();
    }   //由于是反向迭代器，所以_x < _y 实际为 _x的指针指向后面

    template<typename _Iterator>
    inline bool
    operator!=(const reverse_iterator<_Iterator> &_x,
               const reverse_iterator<_Iterator> &_y) { return !(_x == _y); }

    template<typename _Iterator>
    inline bool
    operator>(const reverse_iterator<_Iterator> &_x,
              const reverse_iterator<_Iterator> &_y) { return _y < _x; }

    template<typename _Iterator>
    inline bool
    operator<=(const reverse_iterator<_Iterator> &_x,
               const reverse_iterator<_Iterator> &_y) { return !(_y < _x); }

    template<typename _Iterator>
    inline bool
    operator>=(const reverse_iterator<_Iterator> &_x,
               const reverse_iterator<_Iterator> &_y) { return !(_x < _y); }

    template<typename _Iterator>
    inline typename reverse_iterator<_Iterator>::difference_type
    operator-(const reverse_iterator<_Iterator> &_x,
              const reverse_iterator<_Iterator> &_y) { return _y.base() - _x.base(); }

    template<typename _Iterator>
    inline reverse_iterator<_Iterator>
    operator+(typename reverse_iterator<_Iterator>::difference_type _n,
              const reverse_iterator<_Iterator> &_x) { return reverse_iterator<_Iterator>(_x.base() - _x); }

    //两个模版参数
    template<typename _Iterator_L, typename _Iterator_R>
    inline bool
    operator==(const reverse_iterator<_Iterator_L> &_x,
               const reverse_iterator<_Iterator_R> &_y) { return _x.base() == _y.base(); }

    template<typename _Iterator_L, typename _Iterator_R>
    inline bool
    operator<(const reverse_iterator<_Iterator_L> &_x,
              const reverse_iterator<_Iterator_R> &_y) { return _y.base() < _x.base(); }

    template<typename _Iterator_L, typename _Iterator_R>
    inline bool
    operator!=(const reverse_iterator<_Iterator_L> &_x,
               const reverse_iterator<_Iterator_R> &_y) { return !(_x == _y); }

    template<typename _Iterator_L, typename _Iterator_R>
    inline bool
    operator>(const reverse_iterator<_Iterator_L> &_x,
              const reverse_iterator<_Iterator_R> &_y) { return _y < _x; }

    template<typename _Iterator_L, typename _Iterator_R>
    inline bool
    operator<=(const reverse_iterator<_Iterator_L> &_x,
               const reverse_iterator<_Iterator_R> &_y) { return !(_y < _x); }

    template<typename _Iterator_L, typename _Iterator_R>
    inline bool
    operator>=(const reverse_iterator<_Iterator_L> &_x,
               const reverse_iterator<_Iterator_R> &_y) { return !(_x < _y); }

    template<typename _Iterator_L, typename _Iterator_R>
    inline typename reverse_iterator<_Iterator_L>::difference_type
    operator-(const reverse_iterator<_Iterator_L> &_x,
              const reverse_iterator<_Iterator_R> &_y) { return _y.base() - _x.base(); }
} //namespace mystl

#endif //STL_STL_ITERATOR_H
