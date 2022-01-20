//
// Created by wu on 2022/1/15.
//

#include "sink.h"
namespace tut::log{

    void Sink::setLogLevel(Level::levelNum log_level) {
        m_log_level = log_level;
    }

    Level::levelNum Sink::getLogLevel() const {
        return m_log_level;
    }

    void StdoutSinkBase::log(const logMsg &log_msg) {
        log_mem_buf_t buf;
        m_formatter->format(log_msg,buf);
    }
}