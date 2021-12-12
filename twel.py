#jojoej

class 


data = []
with open("test", "r") as file:
    for line in file:
        cur_line = line[:-1]
        data.append(cur_line)

    print(data)

