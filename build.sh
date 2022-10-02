#!/bin/bash

PROJECT_ROOT=$HOME/Projects/C++/newtonian-physics
OUT_PATH=$HOME/Projects/C++/newtonian-physics/out
FILES_HASHES=$OUT_PATH/hashes.txt
DEBUG_MODE=true

# Create output directory
if [ ! -d $OUT_PATH ]; then
    mkdir $OUT_PATH
fi
# Create files where I will store file hashes
if [ ! -f $FILES_HASHES ]; then
    touch $OUT_PATH/hashes.txt
fi

files_to_compile=()

check_if_files_have_changed_from_the_last_time() {
    for path in $1/*; do
        if [[ -d $path ]]; then
            check_if_files_have_changed_from_the_last_time $path
        else
            new_hash=$(sha1sum $path)
            old_hash=$(grep $path $FILES_HASHES)
            # echo "New hash: $new_hash"
            # echo "Old hash: $old_hash"

            # Compare new and old sha1sum command ignoring spaces

            if [ "$(echo "$new_hash" | tr -d '[:space:]')" = "$(echo "$old_hash" | tr -d '[:space:]')" ]; then
                # File $path didn't change
                echo "$path didn't change"
            else
                # File $path changed

                # add changed file to compile list
                files_to_compile+=($path)
                # replace sleshes with \/ to make sed command work correctly
                old=$(echo $path | sed 's/\//\\\//g')
                new=$(echo $new_hash | sed 's/\//\\\//g')
                # hash strings with new values (update)
                sed -i "s/.*$old.*/$new/g" $FILES_HASHES

                # check if file's string doesn't exist in the file with hashes yet, then add one
                grep $path $FILES_HASHES
                if [[ $(grep $path $FILES_HASHES) = "" ]]; then
                    echo $new_hash >>$FILES_HASHES
                fi
            fi

        fi
    done
}

check_if_files_have_changed_from_the_last_time $PROJECT_ROOT/src

is_failed="false"

echo "*******COMPILATION STAGE***********"
# Compile files from the compile list
for file_to_compile in ${files_to_compile[@]}; do
    echo "Compiling"
    file_name=$(basename $file_to_compile .cpp)
    echo $file_to_compile
    g++ -Wall -Wextra -Werror -g -O0 -c $file_to_compile -o $OUT_PATH/$file_name.o
    if [[ $? -ne 0 ]]; then
        echo "Failed"
        is_failed="true"
    fi
done

if [[ $is_failed = "true" ]]; then
    fail
    echo "" >$FILES_HASHES
    exit 1
fi

echo "*******LINKING STAGE***********"
# link files
g++ -Wall -Wextra -Werror $OUT_PATH/*.o -o $OUT_PATH/programm \
    -L/usr/local/lib \
    /usr/local/lib/libsfml-graphics-d.so \
    /usr/local/lib/libsfml-window-d.so \
    /usr/local/lib/libsfml-system-d.so
