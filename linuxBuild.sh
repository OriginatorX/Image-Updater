echo "Building for linux"

if [ ! -d "$./build" ] 
then
    echo "HI"
    mkdir build && echo DIR build created
fi

cd build
make -f ../Makefile
