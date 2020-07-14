dx = [0, -1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 0, -1, -1, -1, 0, 1, 1, 1]
fish_position_list = list()
directions = list()
fishes = list()
shark_status = [[0, 0], -1] # position : [x, y], direction : [3]

def isSharkMovable(x, y, dir):
    # check whether the shark moves or not
    flag = False
    for step in range(1, 4):
        nx = x + step * dx[dir]
        ny = y + step * dy[dir]
        if nx < 0 or nx > 4 or ny < 0 or ny > 4: 
            continue
        if fishes[nx][ny] > 0:
            flag = True
            break
    
    return flag

def isFishMovable(x, y, dir):
    flag = False
    for step in range(1, 4):
        nx = x + step * dx[dir]
        ny = y + step * dx[dir]
        if nx < 0 or nx > 4 or ny < 0 or ny > 4 or [nx, ny] == shark_status[0]:
            continue
        else:
            flag = True

    return flag

def moveShark():
    # return the number of fish


def moveFishes():
    for i in range(1, 17):
        x = fish_position_list[i][0]
        y = fish_position_list[i][1]
        dir = directions[x][y]
        while not isFishMovable(x, y, dir):
            dir = (dir + 1) % 9
            if dir == 0:
                dir += 1
        if 



def searchWhereFishesAre():
    for i in range(17):
        if i == 0:
            fish_position_list.append(0)
        else:
            for j in range(4):
                for k in range(4):
                    if fishes[j][k] == i:
                        fish_position_list.append([j, k])

def swap(f1, f2):
    temp = [fish_position_list[f2][0], fish_position_list[f2][1]]
    fish_position_list[f2] = f1
    fish_position_list[f1] = temp

def solve():
    searchWhereFishesAre()
    answer = 0
    while(isSharkMovable()):

        eaten_fish = moveShark()
        moveFishes()
        if eaten_fish > answer:
            answer = eaten_fish

    return answer

def inputData():
    l = list()
    l.append([int(x) for x in input().split()])
    for row in l:
        for value, idx in enumerate(row):
            fishes_in_row = []
            directions_in_row = []
            if idx % 2 == 0:
                fishes_in_row.append(value)
            else:
                directions_in_row.append(value)
            fishes.append(fishes_in_row)
            directions.append(directions_in_row)
    
def main():
    inputData()
    solve()

if __name__ == "__main__":
    main()