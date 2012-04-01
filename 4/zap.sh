#!/bin/sh

make zap 1>/dev/null 2>&1
test -e changemod || touch changemod
test -e times || touch times
ls -l changemod times
ls -lu changemod times
ls -lc changemod times
sleep 5
./zap changemod times
ls -l changemod times
ls -lu changemod times
ls -lc changemod times

