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


    };

    //特化void类型
    template<>
    class allocator<void> {
    public:

    };

    //== and !=


} //namespace mystl

#endif //STL_STL_ALLOCATOR_H
