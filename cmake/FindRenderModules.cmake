cmake_minimum_required(VERSION 3.17)

if(NOT TARGET render-modules)
    include(FetchContent)
    FetchContent_Declare(
            render-modules
            GIT_REPOSITORY https://github.com/PolymorphEngine/render-modules.git
            GIT_TAG dev
    )
    FetchContent_MakeAvailable(render-modules)
endif()