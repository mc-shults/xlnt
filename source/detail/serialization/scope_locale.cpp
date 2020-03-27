#include <detail/serialization/scope_locale.hpp>
#include <clocale>

namespace xlnt {
namespace detail {

scope_locale::scope_locale(int category, const char *locale)
    : locale_category(category),
      per_thread_locale_state(_configthreadlocale(0)) //get current state
{
    if (auto current_locale = setlocale(locale_category, nullptr))
        old_locale = current_locale; //not nullptr

    if (per_thread_locale_state != _ENABLE_PER_THREAD_LOCALE)
        _configthreadlocale(_ENABLE_PER_THREAD_LOCALE);

    setlocale(locale_category, locale);
}

scope_locale::~scope_locale()
{
    setlocale(LC_NUMERIC, old_locale.c_str());

    if (per_thread_locale_state != _ENABLE_PER_THREAD_LOCALE)
        _configthreadlocale(_DISABLE_PER_THREAD_LOCALE);
}

}// namespace detail
} // namespace xlnt