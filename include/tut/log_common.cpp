//
// Created by wu on 2022/1/15.
//

#include "log_common.h"
#include <algorithm>

namespace tut::log::Level {

    const std::string_view &toStringView(Level::levelNum v) noexcept {
        // todo: v >= level_num
        if (v >= levelNum::n_levels)
            return level_string[levelNum::n_levels - 1];
        return level_string[v];
    }

    levelNum fromString(const std::string &name) noexcept {
        auto it = std::find(std::begin(level_string), std::end(level_string), name);
        if (it != std::end(level_string)) {
            return static_cast<levelNum>(it - std::begin(level_string));
        }
        return levelNum::OFF;
    }
}

constexpr tut::log::source_loc::source_loc(const char *filename_, int line_num_, const char *func_name_)
        : file_name(filename_),
          line_num(line_num_),
          func_name(func_name_) {

}
