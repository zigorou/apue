add_executable(seek seek.c)

add_executable(hole hole.c)
target_link_libraries(hole apue)

add_executable(fileflags fileflags.c)
target_link_libraries(fileflags apue)

add_executable(mycat_buf mycat_buf.c)
target_link_libraries(mycat_buf apue)

add_executable(mycat2 mycat2.c)
target_link_libraries(mycat2 apue)
