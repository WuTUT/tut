include(FetchContent)
FetchContent_Declare(fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG master
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ext/fmt
        )
FetchContent_MakeAvailable(fmt)
