// Copyright (c) 2014-2018 Thomas Fussell
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, WRISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE
//
// @license: http://www.opensource.org/licenses/mit-license.php
// @author: see AUTHORS file

#include <xlnt/styles/style.hpp>
#include <xlnt/xlnt.hpp>
#include <helpers/test_suite.hpp>

class style_test_suite : public test_suite
{
public:
    style_test_suite()
    {
        register_test(test_all);
    }

    void test_all()
    {
        xlnt::workbook wb;
        auto test_style = wb.create_style("test_style");
        test_style.number_format(xlnt::number_format::date_ddmmyyyy());

        auto copy_style(test_style);
        xlnt_assert_equals(test_style, copy_style);

        // number format
        xlnt_assert_equals(copy_style.name(), "test_style");
        copy_style.name("test_style_2");
        xlnt_assert_equals(copy_style.name(), "test_style_2");
        xlnt_assert_equals(copy_style.number_format(), xlnt::number_format::date_ddmmyyyy());
        //xlnt_assert(!copy_style.number_format_applied()); // this doesn't seem to have sensible behaviour?
        copy_style.number_format(xlnt::number_format::date_datetime(), true); // true applied param
        xlnt_assert_equals(copy_style.number_format(), xlnt::number_format::date_datetime());
        xlnt_assert(copy_style.number_format_applied());
        copy_style.number_format(xlnt::number_format::date_dmminus(), false); // false applied param
        xlnt_assert_equals(copy_style.number_format(), xlnt::number_format::date_dmminus());
        xlnt_assert(!copy_style.number_format_applied());

        xlnt_assert(!copy_style.pivot_button());
        copy_style.pivot_button(true);
        xlnt_assert(copy_style.pivot_button());

        xlnt_assert(!copy_style.quote_prefix());
        copy_style.quote_prefix(true);
        xlnt_assert(copy_style.quote_prefix());

		xlnt_assert(!copy_style.hidden());
        copy_style.hidden(true);
		xlnt_assert(copy_style.hidden());

		xlnt_assert(!copy_style.alignment_applied());
		xlnt::alignment alignment;
		alignment.vertical(xlnt::vertical_alignment::center);
		copy_style.alignment(alignment, true);
        xlnt_assert(copy_style.alignment_applied());
        xlnt_assert_equals(copy_style.alignment().vertical(), xlnt::vertical_alignment::center);

        copy_style.fill(xlnt::fill::solid(xlnt::color::red()), false);
		xlnt_assert(!copy_style.fill_applied());
        copy_style.fill(xlnt::fill::solid(xlnt::color::red()), true);
        xlnt_assert(copy_style.fill_applied());
        xlnt_assert_equals(copy_style.fill().pattern_fill().type(), xlnt::pattern_fill_type::solid);

		xlnt::border border;
        border.diagonal(xlnt::diagonal_direction::down);
		copy_style.border(border, false);
        xlnt_assert(!copy_style.border_applied());
        copy_style.border(border, true);
        xlnt_assert(copy_style.border_applied());
        xlnt_assert_equals(copy_style.border().diagonal(), xlnt::diagonal_direction::down);

		xlnt::font font;
        font.italic(true);
        copy_style.font(font, false);
        xlnt_assert(!copy_style.font_applied());
        copy_style.font(font, true);
        xlnt_assert(copy_style.font_applied());
        xlnt_assert(copy_style.font().italic());

		xlnt::protection protection;
        protection.locked(true);
        copy_style.protection(protection, false);
        xlnt_assert(!copy_style.protection_applied());
        copy_style.protection(protection, true);
        xlnt_assert(copy_style.protection_applied());
        xlnt_assert(copy_style.protection().locked());

        xlnt_assert(!(test_style != copy_style));
    }
};
static style_test_suite x;
