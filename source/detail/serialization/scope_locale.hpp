#pragma once
#include <string>

namespace xlnt {
namespace detail {

/// <summary>
/// RAII setlocale wrapper
/// </summary>
class scope_locale
{
public:
    scope_locale(int category, const char *locale);
    ~scope_locale();

private:
    int locale_category;
    int per_thread_locale_state;
    std::string old_locale;
};

}
}