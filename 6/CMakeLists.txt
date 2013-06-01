# 6.1
add_executable(getpwnam getpwnam.c)
target_link_libraries(getpwnam apue)

# 6.11
add_executable(get_shadow_passwd get_shadow_passwd.c)
target_link_libraries(get_shadow_passwd apue)

add_executable(my_uname my_uname.c)
target_link_libraries(my_uname apue)

add_executable(my_date my_date.c)
target_link_libraries(my_date apue)