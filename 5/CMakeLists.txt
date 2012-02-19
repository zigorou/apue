# 5.1
add_executable(fgetcfputc fgetcfputc.c)
target_link_libraries(fgetcfputc apue)

# 5.2
add_executable(fgetsfputs fgetsfputs.c)
target_link_libraries(fgetsfputs apue)

# 5.3
add_executable(buf buf.c)
target_link_libraries(buf apue)

# 5.4
add_executable(tempfiles tempfiles.c)
target_link_libraries(tempfiles apue)

# 5.5
add_executable(tempnam tempnam.c)
target_link_libraries(tempnam apue)
