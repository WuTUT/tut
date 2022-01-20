//
// Created by wu on 2022/1/14.
//

#include "log.h"

#include <utility>

namespace tut::log{
    Logger::ptr LoggerManager::getLogger(const std::string &name){
        auto it = m_loggers.find(name);
        return it == m_loggers.end() ? nullptr : it->second;
    }

    Logger::ptr LoggerManager::getDefaultLogger() const {
        return default_logger;
    }

    void LoggerManager::setDefaultLogger(const std::string &name) {
        default_logger = getLogger(name);
    }

    Logger::Logger(std::string name): m_name(std::move(name)), m_sinks() {

    }


    Logger::Logger(std::string name, Sink::ptr single_sink): Logger(std::move(name), {std::move(single_sink)}) {

    }

    template<typename It>
    Logger::Logger(std::string name, It _begin, It _end): m_name(std::move(name)), m_sinks(_begin,_end) {

    }

    Logger::Logger(std::string name, std::initializer_list<Sink::ptr> sinks): Logger(std::move(name),sinks.begin(),sinks.end()) {

    }

    Level::levelNum Logger::getLevel() const {
        return m_level;
    }

    Level::levelNum Logger::getFlushLevel() const {
        return m_flush_level;
    }

    void Logger::setLevel(Level::levelNum log_level) {
        m_level = log_level;
    }

    void Logger::setFlushLevel(Level::levelNum log_flush_level) {
        m_flush_level = log_flush_level;
    }

    bool Logger::shouldLog(Level::levelNum lvl) const {
        return m_level <= lvl;
    }

    void Logger::_log(const logMsg &log_msg) {
        if(shouldLog(log_msg.level_num)){
            _sink_msg(log_msg);

            if(shouldFlush(log_msg.level_num)){
                _flush();
            }
        }
    }

    void Logger::_sink_msg(const logMsg &logMsg) {
        for(auto& sink : m_sinks){
            sink->log(logMsg);
        }
    }

    bool Logger::shouldFlush(Level::levelNum lvl) const {
        return m_flush_level <= lvl;
    }

    void Logger::_flush() {
        for(auto &sink : m_sinks){
            sink->flush();
        }
    }


}

