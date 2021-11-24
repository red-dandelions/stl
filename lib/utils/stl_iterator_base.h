//
// Created by red-dandelions on 2021/11/24.
//
/*******************************************************************************
 * 这个头文件实现了：
 * 五种迭代器类型
 * iterator迭代器
 * 迭代器萃取器，对原生指针进行偏特化处理
 *
 * 对迭代器进行移动，距离计算的函数，实现了
 * distance函数、advance函数、next函数和prev函数
 ******************************************************************************/
#ifndef STL_STL_ITERATOR_BASE_H
#define STL_STL_ITERATOR_BASE_H

#include "stl_def.h"
#include "stl_except.h"

namespace mystl
{
    /**
     * 定义五种迭代器类型
     * input_iterator_tag               输入迭代器
     * output_iterator_tag              输出迭代器
     * forward_iterator_tag             前向迭代器
     * bidirectional_iterator_tag       双向迭代器
     * random_access_iterator_tag       随机访问迭代器
     */
    struct input_iterator_tag                                               {};
    struct output_iterator_tag                                              {};
    struct forward_iterator_tag : public input_iterator_tag                 {};
    struct bidirectional_iterator_tag : public forward_iterator_tag         {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag   {};

    /**
     * iterator迭代器
     */
    template<typename _Category, typename _Tp, typename _Distance = ptrdiff_t,
            typename _Pointer = _Tp*, typename _Reference = _Tp&>
    struct iterator {
        typedef _Category   iterator_category;
        typedef _Tp         value_type;
        typedef _Distance   difference_type;
        typedef _Pointer    pointer;
        typedef _Reference  reference;
    };

    /**
     *  迭代器萃取器
     *  萃取
     *  iterator_category
     *  value_type
     *  difference_type
     *  pointer
     *  reference
     *
     * 对于原生指针进行偏特化
     *
     * function: __iterator_category 获取iterator_categoory的语法糖
     */

    template<typename _Iterator>
    struct iterator_traits {
        typedef typename _Iterator::iterator_category   iterator_category;
        typedef typename _Iterator::value_type          value_type;
        typedef typename _Iterator::difference_type     difference_type;
        typedef typename _Iterator::pointer             pointer;
        typedef typename _Iterator::reference           reference;
    };

    template<typename _Tp>
    struct iterator_traits<_Tp*> {
        typedef random_access_iterator_tag  iterator_category;
        typedef _Tp                         value_type;
        typedef ptrdiff_t                   difference_type;
        typedef _Tp*                        pointer;
        typedef _Tp&                        reference;
    };

    template<typename _Tp>
    struct iterator_traits<const _Tp*> {
        typedef random_access_iterator_tag  iterator_category;
        typedef _Tp                         value_type;
        typedef ptrdiff_t                   difference_type;
        typedef _Tp*                        pointer;
        typedef _Tp&                        reference;
    };

    template<typename _Iterator>
    inline typename iterator_traits<_Iterator>::iterator_category
    __iterator_category(const _Iterator&)
    { return typename iterator_category<_Iterator>::iterator_category(); }


    /**
     * function模块
     * 包含distance、advance、next、prev函数
     * distance能适配输入迭代器和随机访问迭代器
     * advance能适配输入迭代器、双向迭代器和随机访问迭代器
     * next将迭代器往后移一位
     * prev将迭代器往前移一位
     */
    //distance函数
    template<typename _InputIterator>
    inline typename iterator_traits<_InputIterator>::difference_type
    __distance(_InputIterator __first, _InputIterator __last, input_iterator_tag) {
        typename iterator_traits<_InputIterator>::difference_type __n = 0;
        while (__first != __last) {
            ++__first;
            ++__n;
        }
        return __n;
    }
    template<typename _RandomAccessIterator>
    inline typename iterator_traits<_RandomAccessIterator>::difference_type
    __distance(_RandomAccessIterator __first, _RandomAccessIterator __last) {
        return __last - __first;
    }
    template<typename _InputIterator>
    inline typename iterator_traits<_InputIterator>::difference_type
    distance(_InputIterator __first, _InputIterator __last) {
        return stl::__distance(__first, __last, stl::__iterator_category(__first));
    }

    //advance
    template<typename _InputIterator, typename _Distance>
    inline void
    __advance(_InputIterator& __index, _Distance __n, input_iterator_tag) {
        stl::STL_DEBUG(__n > 0, "_n is required greater 0 for _InputIterator");
        while (__n--)    ++__index;
    }
    template<typename _BidirectionalIterator, typename _Distance>
    inline void
    __advance(_BidirectionalIterator& __index, _Distance __n, bidirectional_iterator_tag) {
        if (__n > 0) while (__n--)    ++__index;
        else        while (__n++)    --__index;
    }
    template<typename _RandomAccessIterator, typename _Distance>
    inline void
    __advance(_RandomAccessIterator& __index, _Distance __n, random_access_iterator_tag)
    { __index += __n; }
    template<typename _InputIterator, typename _Distance>
    inline void
    advance(_InputIterator& __index, _Distance __n) {
        typename iterator_traits<_InputIterator>::difference_type   __d = __n;
        __advance(__index, __d, __iterator_category(__index));
    }

    //next 函数
    template<typename _ForwardIterator>
    inline _ForwardIterator
    next(_ForwardIterator __x, typename iterator_traits<_ForwardIterator>::difference_type __n = 1) {
        stl::advance(_x, _n);
        return _x;
    }

    //prev 函数
    template<typename _BidirectionalIterator>
    inline _BidirectionalIterator
    prev(_BidirectionalIterator __x,
         typename iterator_traits<_BidirectionalIterator>::difference_type __n = 1) {
        stl::advance(__x, -__n);
        return __x;
    }

} //namespace mystl

#endif //STL_STL_ITERATOR_BASE_H
