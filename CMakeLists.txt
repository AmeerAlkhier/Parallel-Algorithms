cmake_minimum_required(VERSION "3.15.3")


project ("HomeWork")

add_executable("${PROJECT_NAME}" "Main.c")

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
install(FILES "Main.c" DESTINATION src)

include(CTest)

add_test("test1" "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}")
