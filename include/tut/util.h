//
// Created by wu on 2022/1/17.
//

#ifndef TUT_UTIL_H
#define TUT_UTIL_H

#include <ctime>
#include "log_common.h"
namespace tut::log::util{
    log_clock::time_point now() noexcept;
    size_t getThreadId() noexcept;
    int getPid() noexcept;
    std::tm getLocaltime(const std::time_t &log_tt) noexcept;
    template<typename ToDuration>
    ToDuration time_fraction(log_clock::time_point tp){
        using std::chrono::duration_cast;
        using std::chrono::seconds;
        auto duration = tp.time_since_epoch();
        auto secs = duration_cast<seconds>(duration);
        return duration_cast<ToDuration>(duration) - duration_cast<ToDuration>(secs);
    }
}
#endif //TUT_UTIL_H
