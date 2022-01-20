//
// Created by wu on 2022/1/15.
//

#ifndef TUT_SINK_H
#define TUT_SINK_H
#include <memory>
#include "log_msg.h"
#include "log_common.h"
#include "log_formatter.h"

namespace tut::log {
        class Sink {
        public:
            using ptr = std::shared_ptr<Sink>;

            virtual void log(const logMsg& log_msg) = 0;
            virtual void flush() = 0;

            virtual ~Sink() = default;

            void setLogLevel(Level::levelNum log_level);
            [[nodiscard]] Level::levelNum getLogLevel() const;

        protected:
            Level::levelNum m_log_level;
            std::unique_ptr<logFormatter> m_formatter;
        };

        class StdoutSinkBase : public Sink {
        public:
            void log(const logMsg& log_msg) override;
        };
    }
#endif //TUT_SINK_H
