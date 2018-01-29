## Mill

To compile on linux you will need to install:

gtk3.0+ library

Cmake version at least 3.9 

Open terminal in directory where is whole repository and type:  

    cmake .

then type:  

    make
    
to built whole project or 

    make help
    
to see all Makefile options.

If you want to play on single instance type: 

    ./mill

If you want to play on two instances type: 

    ./mill A
    
and open second terminal in same directory and type:   

    ./mill B


## How to install Cmake from : https://askubuntu.com/questions/355565/how-do-i-install-the-latest-version-of-cmake-from-the-command-line

Uninstall the default version provided by Ubuntu's package manager:

    sudo apt-get purge cmake

Go to the official CMake webpage (https://cmake.org/download/), then download and extract the latest version. Update the version and build variables in the following command to get the desired version:

    version=3.10
    build=2
    mkdir ~/temp
    cd ~/temp
    wget https://cmake.org/files/v$version/cmake-$version.$build.tar.gz
    tar -xzvf cmake-$version.$build.tar.gz
    cd cmake-$version.$build/

Install the extracted source by running:

    ./bootstrap
    make -j4
    sudo make install

Test your new cmake version.

    $ cmake --version

Results of cmake --version:

    cmake version 3.10.X

    CMake suite maintained and supported by Kitware (kitware.com/cmake).

