cmake_minimum_required(VERSION 3.0.0)
project(spdlog_issue_1050 VERSION 0.1.0)

add_executable(spdlog_issue_1050 main.cpp)
target_include_directories(spdlog_issue_1050
  PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/thirdparty/spdlog/include"
)
