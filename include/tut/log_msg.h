//
// Created by wu on 2022/1/17.
//

#ifndef TUT_LOG_MSG_H
#define TUT_LOG_MSG_H

#include <string_view>
#include "log_common.h"
#include "util.h"

namespace tut::log {
    class logMsg {
    public:
        logMsg() = default;

        logMsg(std::string_view logger_name, log_clock::time_point log_time, source_loc loc, std::string_view log_msg,
               Level::levelNum levelNum);

        std::string_view logger_name;
        log_clock::time_point log_time;
        source_loc loc;
        size_t tid{0};
        std::string_view log_msg;
        Level::levelNum level_num;

    };
}
#endif //TUT_LOG_MSG_H
