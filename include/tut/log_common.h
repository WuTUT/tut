//
// Created by wu on 2022/1/15.
//

#ifndef TUT_LOG_COMMON_H
#define TUT_LOG_COMMON_H

#include <string>
#include <chrono>
#include <type_traits>
#include <fmt/format.h>

namespace tut::log::Level {
    enum levelNum : int {
        TRACE = 0,
        DEBUG = 1,
        INFO = 2,
        WARN = 3,
        ERROR = 4,
        FATAL = 5,
        OFF = 6,
        n_levels
    };

    constexpr static std::string_view level_string[] = {"TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL", "OFF"};

    const std::string_view &toStringView(levelNum v) noexcept;

    levelNum fromString(const std::string &name) noexcept;
}



namespace tut::log {
    using log_clock = std::chrono::system_clock;
    using log_mem_buf_t = fmt::basic_memory_buffer<char, 250>;
#ifdef __unix__
    using pid_t = int;
    constexpr static std::string_view LOG_EOL{"\n"};
#else
    using pid_t = uint32_t;
    constexpr static std::string_view LOG_EOL{"\r\n"};
#endif

    struct source_loc {
        const char *file_name{nullptr};
        const int line_num{0};
        const char *func_name{nullptr};

        constexpr source_loc() = default;

        constexpr source_loc(const char *filename, int line_num, const char *func_name);
    };

    template<typename T, typename U, std::enable_if_t<!std::is_same<T, U>::value, int> = 0>
    constexpr T conditional_static_cast(U value)
    {
        return static_cast<T>(value);
    }

    template<typename T, typename U, std::enable_if_t<std::is_same<T, U>::value, int> = 0>
    constexpr T conditional_static_cast(U value)
    {
        return value;
    }

}
namespace tut::log::fmt_helper{
    std::string_view toStringView(const log_mem_buf_t& buf) noexcept{
        return {buf.data(),buf.size()};
    }

    void appendStringView(std::string_view view, log_mem_buf_t& buf){
        buf.append(view.begin(),view.end());
    }

    template<typename T>
    void appendInt(T n, log_mem_buf_t& buf){
        fmt::format_int i(n);
        buf.template append(i.data(),i.data() + i.size());
    }


}
#endif //TUT_LOG_COMMON_H
