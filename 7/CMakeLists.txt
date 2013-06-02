# 7.1
add_executable(doatexit doatexit.c)
target_link_libraries(doatexit apue)

# 7.2
add_executable(echoarg echoarg.c)
target_link_libraries(echoarg apue)

# section 7.5
add_executable(my_env1 my_env1.c)
target_link_libraries(my_env1 apue)

add_executable(my_env2 my_env2.c)
target_link_libraries(my_env2 apue)

# 7.5
add_executable(testjmp testjmp.c)
target_link_libraries(testjmp apue)