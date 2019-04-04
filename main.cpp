#include <spdlog/spdlog.h>
#include <spdlog/sinks/null_sink.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <spdlog/async.h>

#include <iostream>
#include <memory>
#include <vector>

int main(int, char**) {
    std::cout << "Creating asynchronous logger" << std::endl;

    spdlog::init_thread_pool(8192, 1);

    std::vector<spdlog::sink_ptr> sinks({
            std::make_shared<spdlog::sinks::null_sink_mt>(),
            std::make_shared<spdlog::sinks::stdout_sink_mt>()
    });

    auto logger =
            std::make_shared<spdlog::async_logger>(
                    "async_logger" , sinks.begin(), sinks.end(),
                    spdlog::thread_pool(),
                    spdlog::async_overflow_policy::overrun_oldest);
    logger->set_level(spdlog::level::info);
    logger->flush_on(spdlog::level::info);

    spdlog::register_logger(logger);
    std::cout << "before logger log" << std::flush;

    logger->info("check with data \n");
    logger->log(spdlog::level::info, " just check sme tect\n");

    std::cout << "after logger log" << std::endl;

    spdlog::shutdown();

    return 0;
}
