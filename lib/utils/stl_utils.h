//
// Created by red-dandelions on 2021/11/24.
//

/**
 * 这个头文件包含判断左值引用和右值引用判断
 * 移除引用
 * move和forward
 * swap
 */
#ifndef STL_STL_UTILS_H
#define STL_STL_UTILS_H

#include "stl_except.h"

namespace mystl
{
    //移除引用
    template<typename _Tp>
    struct remove_reference {
        typedef _Tp     type;
    };
    template<typename _Tp>
    struct remove_reference<_Tp&> {
        typedef _Tp     type;
    };
    template<typename _Tp>
    struct remove_reference<_Tp&&> {
        typedef _Tp     type;
    };

    //判断左值引用， 右值引用
    template<typename _Tp, _Tp __val>
    struct integral_constant {
        static constexpr _Tp                    value = __val;
        typedef _Tp                             value_type;
        typedef integral_constant<_Tp, __val>   type;
        constexpr operator value_type()         { return value; }
    };
    typedef integral_constant<bool, true>   true_type;
    typedef integral_constant<bool, false>  false_type;
    template<typename _Tp>
    struct is_lvalue_reference : public false_type      {};
    template<typename _Tp>
    struct is_lvalue_reference<_Tp&> : public true_type {};
    template<typename _Tp>
    struct is_rvalue_reference : public false_type      {};
    template<typename _Tp>
    struct is_rvalue_reference<_Tp&> : public true_type {};

    //move
    template<typename _Tp>
    constexpr typename mystl::remove_reference<_Tp>::type&&
    move(_Tp&& __t) noexcept {
        return static_cast<typename mystl::remove_reference<_Tp>::type&&>(__t);
    }

    //forward
    template<typename _Tp>
    constexpr _Tp&&
    forward(typename mystl::remove_reference<_Tp>::type& __t) noexcept {
        return static_cast<_Tp&&>(__t);
    }
    template<typename _Tp>
    constexpr _Tp&&
    forward(typename mystl::remove_reference<_Tp>::type&& __t) noexcept {
        STL_DEBUG(is_lvalue_reference<_Tp>::value,
                  "template argument _Tp is an lvalue reference type");
        return static_cast<_Tp&&>(__t);
    }

    //swap
    template<typename _Tp>
    inline void
    swap(_Tp& __a, _Tp& __b) {
        _Tp __tmp   = mystl::move(__a);
        __a         = mystl::move(__b);
        __b         = mystl::move(__tmp);
    }
    template<typename _Tp, size_t __N>
    inline void
    swap(_Tp (&__a)[__N], _Tp (&__b)[__N]) {
        for (size_t __index = 0; __index < __N; __index++) {
            mystl::swap(__a[__index], __b[__index]);
        }
    }

} //namespace mystl

#endif //STL_STL_UTILS_H
