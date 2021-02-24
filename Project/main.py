from os import listdir
from os.path import isfile, join

dir_path = input("Enter the directory path: ")
files = [file for file in listdir(dir_path) if isfile(join(dir_path, file)) and '.csv' in file]
print(*files)
lst = []
for file in files:
    file_path = dir_path + '\\' + file
    with open(file_path) as file_handler:
        for line in file_handler:
            if line[0].isalpha():
                lst.append(line)
    lst.append('\n')
table = [line.split(',') for line in lst]
for el in table:
    print(' '.join(el))
input()
