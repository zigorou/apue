# 6.システムデータファイルと情報

## 6.2 パスワードファイル

 * pwd.h
 * passwd 構造体
 * getpwuid(3), getpwnam(3)
 * getpwent(3), setpwent(3), endpwene(3)
 
サンプルコードは一応、id(1) ライクにしてみました。

## 6.4 グループファイル

 * grp.h
 * group 構造体
 * getgrgid(3), getgrnam(3)
 * getgrent(3), setgrent(3), endgrent(3)
 * この辺は pwd.h の関数群と対をなす感じ

## 6.5 補足グループ ID

 * unistd.h
 * getgroups(3), setgroups(3), initgroups(3)

## 6.6 その他のデータファイル

 * /etc/hosts, /etc/networks, /etc/protocols, /etc/services
 * netdb.h
 * hostent, netent, protoent, servent
 * gethostbyname(3), gethostbyaddr(3)
 * getnetbyname(3), getnetbyaddr(3)
 * getprotobyname(3), getprotobynumber(3)
 * getservbyname(3), getservbyport(3)
 * 図6.3参照
 
## 6.7 ログイン記録

 * utmp, wtmp ファイル
 * utmp 構造体
 * who(1), last(1)

## 6.8 システムの識別

 * uname(3)
 * utsname 構造体
 * gethostname(3)
 
## 6.9 時刻と日付のルーティン

 * time.h
 * time_t
 * time(3)
 * tm 構造体
 * 図 6.4
 * gmtime(3), localtime(3)
 * mktime(3)
 * asctime(3), ctime(3)
 * strftime(3)

## 6.11 演習問題

 - getpwuid(3) または getpwnam(3) で passwd 構造体の値を取得し、そのメンバーの pw_passwd を取得する

