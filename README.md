Installing Compiler

http://www.mingw.org/

On left side, under Popular Content, search for download/installer and MSYS
Download the installer, and install Mingw + MSYS



`g++ -O2 -std=c++14 \"${file}\" -o \"${file_path}\\\\${file_base_name}\" && \"${file_path}\\\\${file_base_name}\" < input.txt -lstdc++"`

