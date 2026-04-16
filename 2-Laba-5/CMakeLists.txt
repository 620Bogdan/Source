cmake_minimum_required(VERSION 3.19)
project(2-Laba-5 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(2-Laba-5
    WIN32 MACOSX_BUNDLE

    mainwindow.cpp
    mainwindow.h
    mainwindow.ui


    rup.h
    person.h
    amp.h
    data.txt
    main.cpp
    img_res.qrc
)

target_link_libraries(2-Laba-5
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS 2-Laba-5
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET 2-Laba-5
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
