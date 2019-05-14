#pragma once
namespace xlnt {

namespace detail {
struct format_impl;
struct stylesheet;
}

class format_impl_ptr
{
public:
    format_impl_ptr(format_impl_ptr &other);
    format_impl_ptr(const format_impl_ptr &other);
    format_impl_ptr(format_impl_ptr&& other);
    ~format_impl_ptr();

    detail::format_impl &operator*();
    const detail::format_impl &operator*() const;
    detail::format_impl *operator->();
    const detail::format_impl *operator->() const;

	format_impl_ptr &operator=(const format_impl_ptr &other);

private:
    friend struct detail::stylesheet;

    format_impl_ptr(detail::format_impl *ptr);
    detail::format_impl *ptr_;
};

} // namespace xlnt
