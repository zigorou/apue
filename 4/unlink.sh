#!/bin/sh

dd bs=10485760 count=1 if=/dev/zero of=tempfile
echo "### start"
ls -l tempfile
df .
echo "### run ./unlink"
./unlink
echo "### exit ./unlink"
df .

