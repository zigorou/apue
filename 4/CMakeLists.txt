# 4.1
add_executable(filetype filetype.c)
target_link_libraries(filetype apue)

# 4.2
add_executable(access access.c)
target_link_libraries(access apue)

# 4.3
add_executable(umask umask.c)
target_link_libraries(umask apue)

# 4.4
add_executable(changemod changemod.c)
target_link_libraries(changemod apue)

# 4.5
option(UNLINK_DEBUG "debugging mode for unlink.c" OFF)
option(UNLINK_SLEEP "wait time for ls" 15)
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/unlink_config.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/unlink_config.h
)
add_executable(unlink unlink.c)
target_link_libraries(unlink apue)

# 4.6
add_executable(zap zap.c)
target_link_libraries(zap apue)

add_executable(zap2 zap2.c)
target_link_libraries(zap2 apue)

# 4.7
add_executable(ftw4 ftw4.c)
target_link_libraries(ftw4 apue)

# 4.8
add_executable(mycd mycd.c)
target_link_libraries(mycd apue)

# 4.9
add_executable(getcwd getcwd.c)
target_link_libraries(getcwd apue)

# 4.10
add_executable(devrdev devrdev.c)
target_link_libraries(devrdev apue)

### examples

# 4.13
add_executable(ftruncate ftruncate.c)
target_link_libraries(ftruncate apue)

# 4.15
add_executable(rename rename.c)
target_link_libraries(rename apue)


### execises 
# 4.1
add_executable(filetype2 filetype2.c)
target_link_libraries(filetype2 apue)

# 4.7
add_executable(mycp mycp.c)
target_link_libraries(mycp apue)

# 4.12
add_executable(ftw4_chdir ftw4_chdir.c)
target_link_libraries(ftw4_chdir apue)

# 4.18
add_executable(mkdir_recursive mkdir_recursive.c)
target_link_libraries(mkdir_recursive apue)

# 4.19
add_executable(unlink_creat unlink_creat.c)
target_link_libraries(unlink_creat apue)