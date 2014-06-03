#!/bin/bash

LOGINUSER=XXX
LOGINHOST=XXX.XXX.XXX.XXX
WEBROOT=/srv/http

# Converts all markdown to hypertext markup

for OUTPUT in $(find . -type f -name '*.md' -exec echo {} \;)
do
    ./convert.sh ${OUTPUT%.md}
done

# Copies all the things to remote server's web directory

scp -r * $LOGINUSER@$LOGINHOST:$WEBROOT
