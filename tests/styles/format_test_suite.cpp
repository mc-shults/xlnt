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

class format_references_test_suite : public test_suite
{
public:
    format_references_test_suite()
    {
        register_test(test_format_references);
    }


    void test_format_references()
    {
        const std::string file_name = "format_references";

        xlnt::workbook wb;
        auto ws = wb.active_sheet();


        for (int row{1}; row <= 10; row++)
        {
            for (int column{1}; column <= 10; column++)
            {
                xlnt::font font;
                font.color(xlnt::color::red());

                auto cell = ws.cell(column, row);
                cell.font(font);
                cell.value("TEST");
            }
        }

        wb.save(file_name);

        wb.load(file_name);
        ws = wb.active_sheet();

        std::vector<xlnt::color> colors = {xlnt::color::red(), xlnt::color::blue(), xlnt::color::green(), xlnt::color::yellow(), xlnt::color::darkblue()};

        for (unsigned row{1}; row <= 10; row++)
        {
            for (unsigned column{1}; column <= 10; column++)
            {
                xlnt::font font;
                font.color(colors[(row + column) % colors.size()]);

                auto cell = ws.cell(column, row);
                cell.font(font);
                cell.value("TEST");
            }
        }

        wb.save(file_name);
    }
};
static format_references_test_suite x;
