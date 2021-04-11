cmake_minimum_required(VERSION 3.5)

project(archpm LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

aux_source_directory(src/pm2/  PM_FILES)
aux_source_directory(src/     UI_CXX_FILES)

set(PROJECT_SOURCES
        src/ui/config.ui
        src/ui/dialog.ui
        src/ui/mainwindow.ui
        src/ui/pkgentry.ui
        src/ui/pkginfo.ui
        src/ui/pkgnote.ui
        ${UI_CXX_FILES}
        ${PM_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(archpm
      ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(archpm SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(archpm
          ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(archpm PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(archpm PUBLIC  alpm)
