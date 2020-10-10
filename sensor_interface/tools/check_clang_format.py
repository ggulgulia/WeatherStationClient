import os
import subprocess
from pathlib import Path

def check_clang_formatter():
    #bin_path  = 'bin/output'
    file_list = []      # The list of .cpp files to be compiled

    for a_file in Path('.').glob('**/*.cpp'):
        file_list.append(str(a_file))

    for a_file in Path('.').glob('**/*.hpp'):
        file_list.append(str(a_file))

    count = 0
    cpp_file_sep = ' '
    command = 'clang-format -i -assume-filename=.clang-format ' + cpp_file_sep.join(file_list) + ' -output-replacements-xml'
    output = subprocess.getoutput(command)
    output_list = output.split()
    for word in output_list:
        print("word: ", word)
        if word == '<replacement':
            print("found:", word)
            count += 1
    print("Found ", count, ' errors with unformatted files! Run \'./tools/clang_formatter.py\'! ')


if __name__ == '__main__':
    check_clang_formatter()
