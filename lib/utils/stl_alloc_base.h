//
// Created by red-dandelions on 2021/11/24.
//
/**
 * 定义allocator_base类，管理内存
 */
#ifndef STL_STL_ALLOC_BASE_H
#define STL_STL_ALLOC_BASE_H

#include <new>

#include "stl_def.h"
#include "stl_except.h"
#include "stl_utils.h"

namespace mystl
{
    /**
     * allocator_base类
     * 使用new申请空间
     * 定义默认、复制、泛化复制、析构函数
     * 负责内存的申请和释放
     *
     * allocate和deallocate负责申请和释放内存
     */

    template<typename _Tp>
    class allocator_base {
    public:
        typedef size_t      size_type;
        typedef ptrdiff_t   difference_type;
        typedef _Tp*        pointer;
        typedef const _Tp*  const_pointer;
        typedef _Tp&        reference;
        typedef const _Tp&  const_reference;
        typedef _Tp         value_type;

        template<typename _Tp1>
        struct rebind {
            typedef allocator_base<_Tp1> other;
        };

        //defalut constructor
        allocator_base() noexcept                               {}
        //copy constructor
        allocator_base(const allocator_base&) noexcept          {}
        //泛化copy constructor
        template<typename _Tp1>
        allocator_base(const allocator_base<_Tp1>&) noexcept    {}
        //defalut destructor
        ~allocator_base() noexcept                              {}
        //get address
        pointer
        address(reference __x) const noexcept {
            return __builtin_addressof(__x);
        }
        const_pointer
        address(const_reference __x) const noexcept {
            return __builtin_addressof(__x);
        }

        //allocate and deallocate
        pointer
        allocate(size_type __n, const void * = 0) {
            if (__n > this->max_size()) STL_BAD_ALLOC;
            return static_cast<_Tp*>(::operator new(__n * sizeof(_Tp)));
        }
        void
        deallocate(pointer __p, size_type) {
            ::operator delete(__p);
        }

        //max_size
        size_type
        max_size() const noexcept {
            return size_t(-1) / sizeof(_Tp);
        }
        //construct and destroy
        template<typename _Tp1, typename... _Args>
        void construct(_Tp1* __p, _Args&&... __args) {
            ::new((void*)__p) _Tp1(mystl::forward<_Args>(__args)...);
        }
        template<typename _Tp1>
        void destroy(_Tp1* __p) {
            __p->~_Tp1();
        }
    };

    //== and !=
    template<typename _Tp>
    inline bool
    operator==(const allocator_base<_Tp>&, const allocator_base<_Tp>&)
    { return true; }

    template<typename _Tp>
    inline bool
    operator!=(const allocator_base<_Tp>&, const allocator_base<_Tp>&)
    { return false; }

} //namespace mystl

#endif //STL_STL_ALLOC_BASE_H
