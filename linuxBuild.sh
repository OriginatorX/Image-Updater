echo "Building for linux"

if [ ! -d "$build/" ]; then
    mkdir build && echo DIR build created
fi

cd build
make -f ../Makefile


