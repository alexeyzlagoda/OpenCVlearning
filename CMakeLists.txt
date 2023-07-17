# CMakeList.txt: проект CMake для CORE; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 2.8)


project ("CORE")

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CORE "CORE.cpp" "CORE.h")
target_link_libraries( DisplayImage ${OpenCV_LIBS} )
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
