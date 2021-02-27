from os import listdir
from os.path import isfile, join
import csv

def get_points(country, position, res):
    """
    This function counts points for the country
    :param country: position of the country in table
    :param position: country's position in rating
    :param res: result list
    :return: void
    """
    if position == 0:
        res[country].append(12)
    elif position == 1:
        res[country].append(10)
    else:
        res[country].append(10 - position)


def parse_files(path):
    """
    This function forms table[country - votes]
    :param path: path to directory
    :return: matrix[country - votes]
    """
    files = [file for file in listdir(path) if isfile(join(path, file)) and '.csv' in file and file != 'result.csv']
    lst = []
    for file in files:
        file_path = path + '\\' + file
        with open(file_path) as file_handler:
            for line in file_handler:
                if line[0].isalpha():
                    lst.append(line)
    parsed_lst = [line.split(',') for line in lst]
    return parsed_lst


def get_rating(table):
    """
    This function forms rating  of all countries from table
    :param table: [country - votes]
    :return: rating [country - points]
    """
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

    rating = []
    for _ in range(10):
        max_votes, ind = 0, 0
        for i in range(len(result)):
            if int(result[i][1]) > max_votes:
                max_votes = int(result[i][1])
                ind = i
        rating.append(result[ind])
        del result[ind]
    return rating


def write_to_file(path, res):
    """
    This function writes result in result.csv file
    :param path: path to directory
    :param res: TOP-10 rating
    :return: void
    """
    with open(path + "\\result.csv", "w", newline='') as f:
        for row in res:
            csv.writer(f).writerow(row)
    print("READY!")


dir_path = input("Enter the directory path: ")
matrix = parse_files(dir_path)
score = get_rating(matrix)
write_to_file(dir_path, score)

input()
