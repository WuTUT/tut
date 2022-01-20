//
// Created by wu on 2022/1/15.
//

#include "log_formatter.h"

namespace tut::log {
    class pidFormatterItem final : public FormatterItem {
        // type is %p
        void format(const logMsg &log_msg, log_mem_buf_t &buf) override {
            fmt_helper::appendInt(util::getPid(), buf);
        }
    };

    class payloadFormatterItem final : public FormatterItem {
        //type is %v
        void format(const logMsg &log_msg, log_mem_buf_t &buf) override {
            fmt_helper::appendStringView(log_msg.log_msg, buf);
        }
    };

    class tidFormatterItem final : public FormatterItem {
        // type is %t
        void format(const logMsg &log_msg, log_mem_buf_t &buf) override {
            fmt_helper::appendInt(log_msg.tid, buf);
        }
    };

    class levelFormatterItem final : public FormatterItem {
        // type is %l
        void format(const logMsg &log_msg, log_mem_buf_t &buf) override {
            fmt_helper::appendStringView(Level::toStringView(log_msg.level_num), buf);
        }
    };

    class filenameFormatterItem final : public FormatterItem {
        // type is %s
        void format(const logMsg &log_msg, log_mem_buf_t &buf) override {
            auto source_file_name = log_msg.loc.file_name;
            auto len = std::strlen(source_file_name);
            fmt_helper::appendStringView(std::string_view(source_file_name, len), buf);
        }
    };

    class lineFormatterItem final : public FormatterItem {
        // type is %#
        void format(const logMsg &log_msg, log_mem_buf_t &buf) override {
            fmt_helper::appendInt(log_msg.loc.line_num, buf);
        }
    };

    class funcnameFormatterItem final : public FormatterItem {
        // type is %!
        void format(const logMsg &log_msg, log_mem_buf_t &buf) override {
            auto source_func_name = log_msg.loc.func_name;
            auto len = std::strlen(source_func_name);
            fmt_helper::appendStringView(std::string_view(source_func_name, len), buf);
        }
    };

    class loggernameFormatterItem final : public FormatterItem {
        // type is %n
        void format(const logMsg &log_msg, log_mem_buf_t &buf) override {
            fmt_helper::appendStringView(log_msg.logger_name, buf);
        }
    };

    class yearFormatterItem final : public FormatterItem {
        // type is %y
        void format(const logMsg &log_msg, log_mem_buf_t &buf) override {

        }
    };

    class monthFormatterItem final : public FormatterItem {
        // type is %m
        void format(const logMsg &log_msg, log_mem_buf_t &buf) override {

        }
    };

    class dayFormatterItem final : public FormatterItem {
        // type is %d
        void format(const logMsg &log_msg, log_mem_buf_t &buf) override {

        }
    };

    class hourFormatterItem final : public FormatterItem {
        // type is %H
        void format(const logMsg &log_msg, log_mem_buf_t &buf) override {

        }
    };

    class minuteFormatterItem final : public FormatterItem {
        // type is %M
        void format(const logMsg &log_msg, log_mem_buf_t &buf) override {

        }
    };

    class secondFormatterItem final : public FormatterItem {
        // type is %S
        void format(const logMsg &log_msg, log_mem_buf_t &buf) override {

        }
    };

    class microsecondFormatterItem final : public FormatterItem {
        // type is %f
        void format(const logMsg &log_msg, log_mem_buf_t &buf) override {
            fmt_helper::appendInt(conditional_static_cast<std::size_t>(
                    util::time_fraction<std::chrono::microseconds>(log_msg.log_time).count()), buf);
        }
    };

    void logFormatter::format(const logMsg &log_msg, log_mem_buf_t &buf) {
        getTime(log_msg);
        for (const auto &it: m_flag_items) {
            it->format(log_msg, buf);
        }
        fmt_helper::appendStringView(LOG_EOL, buf);
    }

    void logFormatter::getTime(const logMsg &log_msg) {
        std::time_t log_tt = log_clock::to_time_t(log_msg.log_time);
        cache_tm = util::getLocaltime(log_tt);
    }

    void logFormatter::compilePattern() {

    }

    void logFormatter::setPattern(std::string pattern) {
        m_pattern = std::move(pattern);
        compilePattern();
    }
}