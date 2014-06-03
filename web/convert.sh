#!/bin/bash

# Takes an argument and converts a markdown file to a mcmackins.guru HTML file

cat HEADER > $1.html
markdown MDHEADER.md >> $1.html
markdown $1.md >> $1.html
cat FOOTER >> $1.html
