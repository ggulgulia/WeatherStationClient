import os
import subprocess
from pathlib import Path

def apply_clang_formatter():
    #bin_path  = 'bin/output'
    file_list = []      # The list of .cpp files to be compiled

    for a_file in Path('.').glob('**/*.cpp'):
        file_list.append(str(a_file))

    for a_file in Path('.').glob('**/*.hpp'):
        file_list.append(str(a_file))
        
    cpp_file_sep = ' '
    command = 'clang-format -i -assume-filename=.clang-format ' + cpp_file_sep.join(file_list)
    print(subprocess.getoutput(command))


if __name__ == '__main__':
    apply_clang_formatter()
