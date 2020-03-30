Installing Compiler

http://www.mingw.org/

On left side, under Popular Content, search for download/installer and MSYS
Download the installer, and install Mingw + MSYS

https://cs.nyu.edu/exact/core/gmp/

https://cygwin.com/install.html


      cd c:\sources\hello


Install MSYS 1.0.11 from http://www.mingw.org/wiki/MSYS
(under heading Previous MSYS versions (up to 1.0.11))

Install to C:\msys

Go to https://gmplib.org/ > Downloads > gmp-6.2.0.tar.xz

Extract to C:\gmp
Make sure there is file C:\gmp\configure

Copy paste all from C:\gmp\gmp-x-y-z to C:\gmp

Then open MSYS and do:

cd C:\gmp
Then type "./configure --enable-cxx", without the quotes into msys terminal

Then type "make"

Then type "make check"

Then type "make install"


Go to CodeBlocks > Settings > Compiler > Linker Settings


Add C:/gmp/.libs/libgmpxx.a

Add C:/gmp/.libs/libgmp.a

(libgmpxx must come before libgmp)

Go to CodeBlocks > Settings > Compiler > Search Directories

Add C:/gmp


g++ "-IC:\gmp\include" -O0 -g3 -Wall -c -fmessage-length=0 -lgmp -lgmpxx -o main.o "..\main.cpp" g++ "-LC:\gmp\lib" -o GMPDebug.exe main.o -lgmp -lgmpxx



-------
g++ prog.cpp -lgmpxx -lgmp -o prog


`g++ -O2 -std=c++14 \"${file}\" -o \"${file_path}\\\\${file_base_name}\" && \"${file_path}\\\\${file_base_name}\" < input.txt -lstdc++"`

