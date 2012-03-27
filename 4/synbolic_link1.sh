#!/bin/sh

make ftw4 1>/dev/null 2>&1 

test -d foo && rm -rf foo
mkdir foo
touch foo/a
ln -s ../foo foo/testdir
ls -l foo
rm -rf foo
