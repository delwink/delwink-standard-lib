#!/bin/bash

# Converts all markdown to hypertext markup

for OUTPUT in $(find . -type f -name '*.md' -exec echo {} \;)
do
    ./convert.sh ${OUTPUT%.md}
done

# Copies all the things to mcmackins.guru's web directory

scp -r * mac@guru:/srv/http
