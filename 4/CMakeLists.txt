add_executable(filetype filetype.c)
target_link_libraries(filetype apue)

add_executable(access access.c)
target_link_libraries(access apue)

add_executable(umask umask.c)
target_link_libraries(umask apue)

add_executable(changemod changemod.c)
target_link_libraries(changemod apue)

add_executable(unlink unlink.c)
target_link_libraries(unlink apue)

add_executable(zap zap.c)
target_link_libraries(zap apue)

add_executable(zap2 zap2.c)
target_link_libraries(zap2 apue)

add_executable(ftw4 ftw4.c)
target_link_libraries(ftw4 apue)

