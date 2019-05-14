#include <xlnt/utils/format_impl_ptr.hpp>
#include <detail/implementations/format_impl.hpp>
#include <detail/implementations/stylesheet.hpp>

namespace xlnt {

format_impl_ptr::format_impl_ptr(format_impl_ptr &&other)
{
    ptr_ = other.ptr_;
    other.ptr_ = nullptr;
}

format_impl_ptr::format_impl_ptr(format_impl_ptr &other)
{
    ptr_ = other.ptr_;
    ptr_->references++;
}

format_impl_ptr::format_impl_ptr(const format_impl_ptr &other)
{
    ptr_ = other.ptr_;
    ptr_->references++;
}

format_impl_ptr::~format_impl_ptr()
{
    if (ptr_ != nullptr)
    {
        ptr_->references--;
        if (ptr_->references == 0)
        {
            ptr_->parent->garbage_collect();
            ptr_ = nullptr;
        }
    }
}

detail::format_impl &format_impl_ptr::operator*()
{
    return *ptr_;
}

const detail::format_impl &format_impl_ptr::operator*() const
{
    return *ptr_;
}

detail::format_impl *format_impl_ptr::operator->()
{
    return ptr_;
}

const detail::format_impl *format_impl_ptr::operator->() const
{
    return ptr_;
}

format_impl_ptr &format_impl_ptr::operator=(const format_impl_ptr &other)
{
    ptr_ = other.ptr_;
    ptr_->references++;
    return *this;
}

format_impl_ptr::format_impl_ptr(detail::format_impl *ptr)
    : ptr_(ptr)
{
    ptr_->references++;
}

} // namespace xlnt
