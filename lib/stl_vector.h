//
// Created by red-dandelions on 2021/11/24.
//
/**
 * 不实现vector<bool>
 */
#ifndef STL_STL_VECTOR_H
#define STL_STL_VECTOR_H

#include "stl_iterator_base.h"
#include "stl_alloc_traits.h"
#include "stl_allocator.h"
#include "stl_utils.h"
#include <initializer_list>

namespace mystl
{
    /**
     * _vector_base
     */
     template<typename _Tp, typename _Alloc>
     struct _vector_base {
         typedef typename __alloc_traits<_Alloc>::template
                 rebind<_Tp>::other _Tp_alloc_type;
         typedef typename __alloc_traits<_Tp_alloc_type>::pointer
            pointer;

         //继承allocator类
         struct vector_impl : public _Tp_alloc_type {
             pointer _m_start;
             pointer _m_finish;
             pointer _m_end_of_storeage;

             vector_impl() : _Tp_alloc_type(), _m_start(0), _m_finish(0), _m_end_of_storeage(0)
             {}

             vector_impl(_Tp_alloc_type const& __a)
             : _Tp_alloc_type(__a), _m_start(0), _m_finish(0), _m_end_of_storeage(0)
             {}

             vector_impl(_Tp_alloc_type&& __a)
             : _Tp_alloc_type(mystl::move(__a)), _m_start(0), _m_finish(0), _m_end_of_storeage(0)
             {}

             void __swap_data(vector_impl& __x) {
                 mystl::swap(_m_start, __x._m_start);
                 mystl::swap(_m_finish, __x._m_finish);
                 mystl::swap(_m_end_of_storeage, __x._m_end_of_storeage);
             }
         };

     public:
         typedef _Alloc allocator_type;

         _Tp_alloc_type&
         _m_get_Tp_allocator() noexcept {
             return *static_cast<_Tp_alloc_type*>(&this->_m_impl);
         }
         const _Tp_alloc_type&
         _m_get_Tp_allocator() const noexcept {
             return *static_cast<const _Tp_alloc_type*>(&this->_m_impl);
         }

         allocator_type
         get_allocator() const noexcept {
             return allocator_type(_m_get_Tp_allocator());
         }

         //构造函数
         _vector_base() : _m_impl() {}

         _vector_base(const allocator_type& __a)
         : _m_impl(__a) {}

         _vector_base(mystl::size_t __n) : _m_impl() {
             _m_create_storage(__n);
         }

         _vector_base(mystl::size_t __n, const allocator_type& __a)
         : _m_impl(__a) {
             _m_create_storage(__n);
         }

         //移动构造函数
         _vector_base(_Tp_alloc_type&& __a) : _m_impl(mystl::move(__a)) {}

         _vector_base(_vector_base&& __v)
         : _m_impl(mystl::move(__v._m_get_Tp_allocator())) {
             this->_m_impl.__swap_data(__v._m_impl);
         }

         _vector_base(_vector_base&& __v, const allocator_type& __a)
         : _m_impl(__a) {
             if (__v.get_allocator() == __a)
                 this->_m_impl.__swap_data(__v._m_impl);
             else {
                 mystl::size_t __n = __v._m_impl._m_finish - __v._m_impl._m_start;
                 _m_create_storage(__n);
             }
         }

         ~_vector_base() {
             _m_deallocator(this->_m_impl._m_start, this->_m_impl._m_end_of_storage
                - this->_m_impl._m_start);
         }

     public:
         vector_impl _m_impl;

         pointer
         _m_allocator(mystl::size_t __n) {
             return __n != 0 ? _m_impl.allocator(__n) : 0;
         }
         void
         _m_deallocator(pointer __p, mystl::size_t __n) {
             if (__p)
                 _m_impl.deallocator(__p, __n);
         }

     private:
         //申请空间
         void
         _m_create_storage(mystl::size_t __n) {
             this->_m_impl._m_start             = this->_m_allocate(__n);
             this->_m_impl._m_finish            = this->_m_impl._m_start;
             this->_m_impl._m_end_of_storage    = this->_m_impl._m_start + __n;
         }
     };

     template<typename _Tp, typename _Alloc = mystl::allocator<_Tp>>
     class vector : protected _vector_base<_Tp, _Alloc> {

     };
} //namespace mystl

#endif //STL_STL_VECTOR_H
