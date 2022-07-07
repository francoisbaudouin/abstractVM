# Sources

set(INCROOT ${PROJECT_SOURCE_DIR}/src)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src)

set(SRC ${SRCROOT}/main.cpp)

set(INCDIRS ${INCROOT})

set(TARGET_NAME abstractVM)

add_executable(${TARGET_NAME} ${SRCROOT}/main.cpp)

add_subdirectory(parser)