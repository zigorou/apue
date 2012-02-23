add_executable(seek seek.c)

add_executable(hole hole.c)
target_link_libraries(hole apue)

add_executable(fileflags fileflags.c)
target_link_libraries(fileflags apue)

add_executable(mycat_buf mycat_buf.c)
target_link_libraries(mycat_buf apue)

add_executable(mycat2 mycat2.c)
target_link_libraries(mycat2 apue)

add_executable(mydup2 mydup2.c)
target_link_libraries(mydup2 apue)

add_executable(o_append_and_lseek o_append_and_lseek.c)
target_link_libraries(o_append_and_lseek apue)

add_executable(dup_and_lseek dup_and_lseek.c)
target_link_libraries(dup_and_lseek apue)

add_executable(open_fdescfs open_fdescfs.c)
target_link_libraries(open_fdescfs apue)
