cmake_minimum_required(VERSION 3.16)

project(DynamicQMLTest VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Gui)

qt_standard_project_setup()

qt_add_executable(appDynamicQMLTest
    main.cpp
)

qt_add_qml_module(appDynamicQMLTest
    URI DynamicQMLTest
    VERSION 1.0
    QML_FILES Main.qml
    QML_FILES ui/Swatch.qml
    QML_FILES ui/QuestionScreen.qml
    SOURCES appmanager.h appmanager.cpp
    SOURCES colorhandler.h colorhandler.cpp
    QML_FILES ui/MenuScreen.qml
    QML_FILES ui/MenuButton.qml
    QML_FILES ui/CheckButton.qml
    SOURCES sessionparameters.h
    SOURCES
    QML_FILES ui/AnswerScreen.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appDynamicQMLTest PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appDynamicQMLTest
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appDynamicQMLTest
    PRIVATE Qt6::Quick
    PRIVATE Qt6::Gui
)

include(GNUInstallDirs)
install(TARGETS appDynamicQMLTest
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
