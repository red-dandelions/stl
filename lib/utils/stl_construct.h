//
// Created by red-dandelions on 2021/11/24.
//
/**
 * 这个头文件包含了
 * __Construct和__Destroy全局函数
 */
#ifndef STL_STL_CONSTRUCT_H
#define STL_STL_CONSTRUCT_H

#include <new>

#include "stl_allocator.h"
#include "stl_alloc_traits.h"
#include "stl_utils.h"

namespace mystl
{
    //construct
    template<typename _Tp, typename... _Args>
    inline void
    __Construct(_Tp* __tp, _Args&&... __args) {
        ::new(static_cast<void*>(__tp)) _Tp(mystl::forward<_Args>(__args)...);
    }

    //destroy
    template<typename _Tp>
    __Destroy(_Tp* __pointer) {
        __pointer->~_Tp();
    }

    template<bool>
    struct __destroy_help {
        template<typename _ForwardIterator>
        static void
        __destroy(_ForwardIterator __first, _ForwardIterator __last) {
            while (__first != __last) {
                mystl::__Destroy(__builtin_addressof(*__first));
                __first++;
            }
        }
    };
    template<>
    struct __destroy_help<true> {
        template<typename _ForwardIterator>
        static void
        __destroy(_ForwardIterator, _ForwardIterator) {}
    };

    template<typename _ForwardIterator>
    inline void
    _Destroy(_ForwardIterator __first, _ForwardIterator __last) {
        typedef typename iterator_traits<_ForwardIterator>::value_type __value_type;
        mystl::__destroy_help<__has_trivial_destructor(__value_type)>::
        __destroy(__first, __last);
    }

    template<typename _ForwardIterator, typename _Allocator>
    void
    _Destroy(_ForwardIterator __first, _ForwardIterator __last,
             _Allocator &_alloc) {
        typedef __alloc_traits <_Allocator> __traits;
        __traits::destroy(_alloc, __builtin_addressof(*__first));
    }

    template<typename _ForwardIterator, typename _Tp>
    inline void
    _Destroy(_ForwardIterator __first, _ForwardIterator __last,
             allocator <_Tp> &) {
        _Destroy(__first, __last);
    }
} //namespace mystl

#endif //STL_STL_CONSTRUCT_H
