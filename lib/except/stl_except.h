//
// Created by red-dandelions on 2021/11/24.
//
/*******************************************************************************
 * 定义抛出异常宏函数
 * STL_BAD_ALLOC                    申请内存失败
 * STL_DEBUG                        静态编译阶段进行断言
 * STL_THROW_INVALID_ARGUMENT       非法参数抛出异常
 * STL_THROW_LENGTH_ERROR           长度出错抛出异常
 * STL_THROW_OUT_OF_RANGE           范围溢出抛出异常
 * STL_THROW_RUNTIME_ERROR          运行时异常
 * STL_THROW_RANGE_ERROR            范围异常
 * STL_THROW_OVERFLOW_ERROR         上溢异常
 * STL_THROW_UNDERFLOW_ERROR        下溢异常
 ******************************************************************************/
#ifndef STL_STL_EXCEPT_H
#define STL_STL_EXCEPT_H

#include <stdexcept>

namespace mystl
{

#define STL_BAD_ALLOC                       (std::__throw_bad_alloc())
#define STL_DEBUG(expr, what)               (static_assert((expr), (what)))
#define STL_THROW_INVALID_ARGUMENT(what)    (throw std::invalid_argument(what))
#define STL_THROW_LENGTH_ERROR(what)        (throw std::length_error(what))
#define STL_THROW_OUT_OF_RANGE(what)        (throw std::out_of_range(what))
#define STL_THROW_RUNTIME_ERROR(what)       (throw std::runtime_error(what))
#define STL_THROW_RANGE_ERROR(what)         (throw std::range_error(what))
#define STL_THROW_OVERFLOW_ERROR(what)      (throw std::overflow_error(what))
#define STL_THROW_UNDERFLOW_ERROR(what)     (throw std::underflow_error(what))

} //namespace mystl

#endif //STL_STL_EXCEPT_H
