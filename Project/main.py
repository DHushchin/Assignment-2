from os import listdir
from os.path import isfile, join

dir_path = input("Enter the directory path: ")
files = [file for file in listdir(dir_path) if isfile(join(dir_path, file)) and '.csv' in file]
print(*files)
table = []
for file in files:
    file_path = dir_path + '\\' + file
    f = open(file_path)
    data = f.readlines()
    print(data)
    for i in range(len(data)):
        if i != 0:
            table += data[i]
    f.close()
print(*table)
