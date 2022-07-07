set(INCROOT ${INCROOT}/parser)
set(SRCROOT ${SRCROOT}/parser)

set(SRC
    ${SRC}
    ${SRCROOT}/Parser.cpp
    ${SRCROOT}/Parser.hpp
    PARENT_SCOPE)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE)
