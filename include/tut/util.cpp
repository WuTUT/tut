//
// Created by wu on 2022/1/17.
//

#include "util.h"


#ifdef __unix__
#include <unistd.h>
#include <sys/syscall.h>
#endif

namespace tut::log::util{

    log_clock::time_point now() noexcept {
        return log_clock::now();
    }



    inline size_t _getThreadId() noexcept {
#ifdef __unix__
        return conditional_static_cast<size_t>(syscall(SYS_gettid));
#else
        return conditional_static_cast<size_t>(std::hash<std::thread::id>()(std::this_thread::get_id()));
#endif
    }

    size_t getThreadId() noexcept {
        static thread_local const size_t tid = _getThreadId();
        return tid;
    }

    pid_t getPid() noexcept {
#ifdef __unix__
        return conditional_static_cast<pid_t>(syscall(SYS_getpid));
#else
        //TODO : WIN32 not implemented
        return -1;
#endif
    }

    std::tm getLocaltime(const std::time_t &log_tt) noexcept {
        std::tm tm;
#ifdef __unix__
        localtime_r(&log_tt, &tm);
#else
        localtime_s(&tm, &logt_tt);
#endif
        return tm;
    }
}