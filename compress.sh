#!/bin/bash
set -e

# The assignment requirement is handing a .zip archive with .cpp files in it.
# I wrote those C files with .c suffix (shouldn't it be?).
# I can't be bothered to type these commands by hand.
#
# $1 = Directory to operate.
#   - If it's "clear", all .zip files will be removed.
#   - If not specified, the current dir is used.

function pack {
  DIR="$1"
  cd "$DIR"

  # Copy all .c files with .cpp suffix
  for i in *.c; do
    cp $i ${i/.c/.cpp}
  done

  # Strip spaces in the directory name as the prefix of .zip file
  # Note that we have already entered the target directory, so use pwd
  ZIP_PREFIX=$(basename "`pwd`" | tr -d '[:space:]')

  # Honor privacy
  # If I want only .cpp files I can C-c here
  while [[ ! -n "$ID" ]]; do
    echo Your ID please.
    read ID
  done

  zip "$ZIP_PREFIX"_"$ID" *.cpp

  # Remove useless things
  rm -f *.cpp
}

function remove_zips {
  find -name 'Lab*_*.zip' -exec rm -f {} \;
}

if [[ "$1" == "clear" ]]; then
  remove_zips
  exit
fi

pack "$1"
