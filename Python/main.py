from os import listdir
from os.path import isfile, join

def get_points(country, position, res):
    if position == 0:
        res[country].append(12)
    elif position == 1:
        res[country].append(10)
    else:
        res[country].append(10 - position)


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
table = [line.split(',') for line in lst]
result = [[table[line][0]] for line in range(len(table))]
for j in range(1, len(table[0])):
    tmp = []
    for i in range(len(table)):
        tmp.append(int(table[i][j]))
    tmp.sort(reverse=True)
    for k in range(len(table)):
        for pos in range(10):
            if int(table[k][j]) == tmp[pos]:
                get_points(k, pos, result)

for res_line in result:
    points = 0
    for i in range(1, len(res_line)):
        points += int(res_line[i])
    del res_line[1:len(res_line)]
    res_line.append(str(points))

for line in result:
    print(line)
input()
