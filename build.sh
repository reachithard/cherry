
set -eux

function build()
{
    rm -rf build/
    mkdir build
    cd build
    cmake  -DCMAKE_VERBOSE_MAKEFILE=on ..
    make -j4
}

function build_deps()
{
    rm -rf build/
    mkdir build
    cd build
    cmake  -DBUILD_DEPS=true -DCMAKE_VERBOSE_MAKEFILE=on ..
    make -j4
}

if test $1 = "-r"
then
    git submodule init
    git submodule update
    echo "下载编译库"
elif test $1 = "-d"
then
    echo '编译依赖库'
    build_deps
elif test $1 = "-b"
then
     echo '编译'
     build
else
    echo '错误使用'
fi

