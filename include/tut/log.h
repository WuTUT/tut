//
// Created by wu on 2022/1/14.
//

#ifndef TUT_LOG_H
#define TUT_LOG_H

#include <memory>
#include <unordered_map>
#include <string>
#include <list>
#include "singleton.h"
#include "sink.h"
#include "log_common.h"
#include "log_msg.h"

namespace tut::log {


    class Logger {
    public:
        using ptr = std::shared_ptr<Logger>;

        explicit Logger(std::string name);
        Logger(std::string name, Sink::ptr single_sink);

        template<typename It>
        Logger(std::string name, It _begin, It _end);

        Logger(std::string name, std::initializer_list<Sink::ptr> sinks);

        [[nodiscard]] Level::levelNum getLevel() const;
        [[nodiscard]] Level::levelNum getFlushLevel() const;
        void setLevel(Level::levelNum log_level);
        void setFlushLevel(Level::levelNum log_flush_level);

        [[nodiscard]] bool shouldLog(Level::levelNum lvl) const;
        [[nodiscard]] bool shouldFlush(Level::levelNum lvl) const;
        void _log(const logMsg& log_msg);
        void _sink_msg(const logMsg& logMsg);
        void _flush();

    private:
        std::list<Sink::ptr> m_sinks;
        std::string m_name;
        Level::levelNum m_level{Level::levelNum::INFO};
        Level::levelNum m_flush_level{Level::levelNum::WARN};
    };

    class LoggerManager {
    public:
        using ptr = std::unique_ptr<LoggerManager>;
        Logger::ptr getLogger(const std::string& name);
        Logger::ptr getDefaultLogger() const;
        void setDefaultLogger(const std::string& name);
    private:
        std::unordered_map<std::string, Logger::ptr> m_loggers;
        Logger::ptr default_logger;
    };
    using loggerMgr = tut::Singleton<LoggerManager>;


}
#endif //TUT_LOG_H
