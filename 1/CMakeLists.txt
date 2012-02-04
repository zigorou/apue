add_executable(myls myls.c)
target_link_libraries(myls apue)

add_executable(mycat mycat.c)
target_link_libraries(mycat apue)

add_executable(getcputc getcputc.c)
target_link_libraries(getcputc apue)

add_executable(hello hello.c)

add_executable(shell1 shell1.c)
target_link_libraries(shell1 apue)

add_executable(testerror testerror.c)
add_executable(uidgid uidgid.c)

add_executable(shell2 shell2.c)
target_link_libraries(shell2 apue)

