echo "Building for linux"

if [ -d ./build ] 
then
    rm -r build && echo DIR build deleted    
fi

mkdir build && echo DIR build created
cd build
make -f ../Makefile
