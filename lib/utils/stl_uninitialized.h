//
// Created by red-dandelions on 2021/11/24.
//

#ifndef STL_STL_UNINITIALIZED_H
#define STL_STL_UNINITIALIZED_H

#include "stl_algorithm.h"
#include "stl_iterator_base.h"
#include "stl_construct.h"
#include "stl_except.h"

namespace mystl {
    /**
     * uninitialized_copy函数
     * 复制range[first, last) into result
     * 返回__result + (__last - __first)
     */
    template<bool _TrivialValueTypes>
    struct __uninitialized_copy {
        template<typename _InputIterator, typename _ForwardIterator>
        static _ForwardIterator
        __uninit_copy(_InputIterator __first, _InputIterator __last,
                      _ForwardIterator __result) {
            _ForwardIterator __cur = __result;
            try {
                for (; __first != __last; ++__first, ++__cur)
                    mystl::__Construct(__builtin_addressof(*__cur), *__first);
                return __cur;
            } catch(...) {
                mystl::_Destroy(__result, __cur);
            }
        }
    };
    template<>
    struct __uninitialized_copy<true> {
        template<typename _InputIterator, typename _ForwardIterator>
        static _ForwardIterator
        __uninit_copy(_InputIterator __first, _InputIterator __last,
                      _ForwardIterator __result) {
            return mystl::copy(__first, __last, __result);
        }
    };
    template<typename _InputIterator, typename _ForwardIterator>
    inline _ForwardIterator
    uninitialized_copy(_InputIterator __first, _InputIterator __last,
                       _ForwardIterator __result) {
        typedef typename iterator_traits<_InputIterator>::value_type
                _ValueType1;
        typedef typename iterator_traits<_ForwardIterator>::value_type
                _ValueType2;

        return mystl::__uninitialized_copy<(__is_trivial(_ValueType1)
                                          && __is_trivial(_ValueType2))>::
        __uninit_copy(__first, __last, __result);
    }

    /**
     * 将x填充range[first, last)
     * @return nothing
     * @tparam _TrivialValueType
     */
    template<bool _TrivialValueType>
    struct __uninitialized_fill {
        template<typename _ForwardIterator, typename _Tp>
        static void
        __uninit_fill(_ForwardIterator __first, _ForwardIterator __last,
                      const _Tp &__x) {
            _ForwardIterator __cur = __first;
            try {
                for (; __cur != __last; ++__cur)
                    mystl::__Construct(__builtin_addressof(*__cur), __x);
            } catch(...) {
                mystl::_Destroy(__first, __cur);
            }
        }
    };
    template<>
    struct __uninitialized_fill<true> {
        template<typename _ForwardIterator, typename _Tp>
        static void
        __uninit_fill(_ForwardIterator __first, _ForwardIterator __last,
                      const _Tp &__x) {
            mystl::fill(__first, __last, __x);
        }
    };
    template<typename _ForwardIterator, typename _Tp>
    inline void
    uninitialized_fill(_ForwardIterator __first, _ForwardIterator __last,
                       const _Tp &__x) {
        typedef typename iterator_traits<_ForwardIterator>::value_type
                _ValueType;
        mystl::__uninitialized_fill<__is_trivial(_ValueType)>::
        __uninit_fill(__first, __last, __x);
    }

    /**
     * 复制x到range[first, first + n)
     * @return nothing
     * @tparam _TrivialValueType
     */
    template<bool _TrivialValueType>
    struct __uninitialized_fill_n {
        template<typename _ForwardIterator, typename _Size, typename _Tp>
        static void
        __uninit_fill_n(_ForwardIterator __first, _Size __n,
                        const _Tp &__x) {
            _ForwardIterator __cur = __first;
            try {
                for (; __n > 0; --__n, ++__cur)
                    mystl::__Construct(__builtin_addressof(*__cur), __x);
            } catch(...) {
                mystl::_Destroy(__first, __cur);
            }
        }
    };
    template<>
    struct __uninitialized_fill_n<true> {
        template<typename _ForwardIterator, typename _Size, typename _Tp>
        static void
        __uninit_fill_n(_ForwardIterator __first, _Size __n,
                        const _Tp &__x) {
            mystl::fill_n(__first, __n, __x);
        }
    };
    template<typename _ForwardIterator, typename _Size, typename _Tp>
    inline void
    uninitialized_fill_n(_ForwardIterator __first, _Size __n, const _Tp &__x) {
        typedef typename iterator_traits<_ForwardIterator>::value_type
                _ValueType;
        mystl::__uninitialized_fill_n<__is_trivial(_ValueType)>::
        __uninit_fill_n(__first, __n, __x);
    }

    template<typename _InputIterator, typename _Size,
            typename _ForwardIterator>
    _ForwardIterator
    __uninitialized_copy_n(_InputIterator __first, _Size __n,
                           _ForwardIterator __result, input_iterator_tag) {
        _ForwardIterator __cur = __result;
        try {
            for (; __n > 0; --__n, ++__first, ++__cur)
                mystl::__Construct(__builtin_addressof(*__cur), *__first);
            return __cur;
        } catch(...) {
            mystl::_Destroy(__result, __cur);
        }
    }

    template<typename _RandomAccessIterator, typename _Size,
            typename _ForwardIterator>
    inline _ForwardIterator
    __uninitialized_copy_n(_RandomAccessIterator __first, _Size __n,
                           _ForwardIterator __result,
                           random_access_iterator_tag) {
        return mystl::uninitialized_copy(__first, __first + __n, __result);
    }
    template<typename _InputIterator, typename _Size, typename _ForwardIterator>
    inline _ForwardIterator
    uninitialized_copy_n(_InputIterator __first, _Size __n,
                         _ForwardIterator __result) {
        return mystl::__uninitialized_copy_n(__first, __n, __result,
                                           mystl::__iterator_category(__first));
    }
} //namespace mystl

#endif //STL_STL_UNINITIALIZED_H
