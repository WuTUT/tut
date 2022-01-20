//
// Created by wu on 2022/1/15.
//

#ifndef TUT_LOG_FORMATTER_H
#define TUT_LOG_FORMATTER_H
#include <memory>
#include <vector>
#include "log_msg.h"
#include "log_common.h"
namespace tut::log{
    class FormatterItem{
    public:
        virtual ~FormatterItem() = default;
        virtual void format(const logMsg& log_msg, log_mem_buf_t& buf) = 0;
    };
    class logFormatter{
    public:
        void format(const logMsg& log_msg, log_mem_buf_t& buf);
        void getTime(const logMsg& log_msg);
        void compilePattern();
        void setPattern(std::string pattern);
    private:
        std::vector<std::unique_ptr<FormatterItem>> m_flag_items;
        std::tm cache_tm;
        std::string m_pattern;
    };
}
#endif //TUT_LOG_FORMATTER_H
