//
// Created by red-dandelions on 2021/11/24.
//
/**
 * 定义allocator类，用来管理容器的内存申请和释放
 */
#ifndef STL_STL_ALLOCATOR_H
#define STL_STL_ALLOCATOR_H

#include "stl_alloc_base.h"

namespace mystl
{
    /**
     * allocator类, 继承allocator_base
     *
     * 管理容器的内存
     * 特化void类型
     */
    template<typename _Tp>
    class allocator : public allocator_base<_Tp> {
    public:
        typedef mystl::size_t       size_type;
        typedef mystl::ptrdiff_t    difference_type;
        typedef _Tp*                pointer;
        typedef const _Tp*          const_pointer;
        typedef _Tp&                reference;
        typedef const _Tp&          const_reference;
        typedef _Tp                 value_type;

        template<typename _Tp1>
        struct rebind {
            typedef allocator<_Tp1> other;
        };

        allocator() throw() {}

        allocator(const allocator& __a) throw()
        : allocator_base<_Tp>(__a) {}

        template<typename _Tp1>
        allocator(const allocator<_Tp1>&) throw() {}

        ~allocator() throw() {}
    };

    //特化void类型
    template<>
    class allocator<void> {
    public:
        typedef mystl::size_t       size_type;
        typedef mystl::ptrdiff_t    difference_type;
        typedef void*               pointer;
        typedef const void*         const_pointer;
        typedef void                value_type;

        template<typename _Tp1>
        struct rebind {
            typedef allocator<_Tp1> other;
        };
    };

    //== and !=
    template<typename _Tp1, typename _Tp2>
    inline bool
    operator==(const allocator<_Tp1>&, const allocator<_Tp2>&) {
        return true;
    }
    template<typename _Tp>
    inline bool
    operator==(const allocator<_Tp>&, const allocator<_Tp>&) {
        return true;
    }
    template<typename _Tp1, typename _Tp2>
    inline bool
    operator!=(const allocator<_Tp1>&, const allocator<_Tp2>&) {
        return false;
    }
    template<typename _Tp>
    inline bool
    operator!=(const allocator<_Tp>&, const allocator<_Tp>&) {
        return false;
    }

    template<typename _Alloc, bool = __is_empty(_Alloc)>
    struct __alloc_swap {
        static void _S_do_it(_Alloc&, _Alloc&) {}
    };

    template<typename _Alloc>
    struct __alloc_swap<_Alloc, false> {
        static void
        _S_do_it(_Alloc& __one, _Alloc& __two) {
            if (__one != __two)
                swap(__one, __two);
        }
    };

} //namespace mystl

#endif //STL_STL_ALLOCATOR_H
