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


     };
} //namespace mystl

#endif //STL_STL_VECTOR_H
