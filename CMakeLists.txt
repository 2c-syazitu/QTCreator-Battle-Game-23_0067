cmake_minimum_required(VERSION 3.16)

project(tasukete VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(tasukete
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        system/battlesystem.h system/Battlesystem.cpp
        system/select.h system/select.cpp system/select.ui
        character/player.h character/player.cpp character/player.ui
        character/characterlist.h character/characterlist.cpp
        character/createcharacter.h character/createcharacter.cpp
        system/turn.h system/turn.cpp
        skill/skill.h skill/skill.cpp
        skill/icesword.h skill/icesword.cpp
        skill/skilllist.h skill/skilllist.cpp skill/skilllist.ui
        character/character.h character/character.cpp
        character/enemy.h character/enemy.cpp character/enemy.ui
        skill/attack.h skill/attack.cpp
        skill/heal.h skill/heal.cpp

        skill/atkbuff.h skill/atkbuff.cpp
        character/buff.h character/buff.cpp character/buff.ui









    )

    qt_add_resources(tasukete "enemy_resources"
        PREFIX "/"
        FILES
            character/enemyImage/doragon.png
            character/playerImage/power.png
            skill/buffIcon/power.png
    )

# Define target properties for Android with Qt 6 as:
#    set_property(TARGET tasukete APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(tasukete SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(tasukete
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(tasukete PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

target_include_directories(tasukete
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/skill
        ${CMAKE_CURRENT_SOURCE_DIR}/character
        ${CMAKE_CURRENT_SOURCE_DIR}/system
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.tasukete)
endif()
set_target_properties(tasukete PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS tasukete
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(tasukete)
endif()
