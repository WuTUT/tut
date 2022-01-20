//
// Created by wu on 2022/1/17.
//

#include "log_msg.h"

namespace tut::log {

    logMsg::logMsg(std::string_view logger_name_, log_clock::time_point log_time_, source_loc loc_,
                   std::string_view log_msg_, Level::levelNum lvl_num)
            : logger_name(logger_name_),
              log_time(log_time_),
              loc(loc_),
              tid(util::getThreadId()),
              log_msg(log_msg_),
              level_num(lvl_num) {
    }


}