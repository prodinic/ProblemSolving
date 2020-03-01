def assign_resource(MAP, di, depth):  # 맵에 원하는 방향으로 자원을 할당한다. depth는 해당 자원의 순서
    global y, x  # 현재 위치를 나타내는 전역변수
    ny, nx = y + diff[di][0], x + diff[di][1]  # 주어진 방향으로 ny, nx 계산
    if 0 <= ny < R and 0 <= nx < C:
        if not MAP[ny][nx]:  # 계산된 위치가 0 이라면
            bv = best_value(ny, nx)  # ny, nx 위치의 best 값 할당
            MAP[ny][nx] = bv  # 지도에 best값 표시
            answer[depth] = bv  # 해당 자원순서에 best값 할당
            cnt[bv] += 1  # 해당 best값 count 배열 + 1
            y, x = ny, nx  # 계산된 위치를 현재위치로 전역 변수 업데이트해줌.
 
        else:  # 계산된 위치가 0 이 아닐 때(뭔가 막혀서 원하는 방향 진행 안되니까 다른 방향 호출)
            if di == 0:  # 우상향이었다면, 우하향 호출
                assign_resource(MAP, 3, depth)
            elif di == 1:  # 좌상향 이었다면, 상향 호출
                assign_resource(MAP, 4, depth)
            elif di == 2:  # 좌하향 이었다면, 좌상향 호출
                assign_resource(MAP, 1, depth)
            elif di == 3:  # 우하향 이었다면, 하향 호출
                assign_resource(MAP, 5, depth)
            elif di == 4:  # 상향 이었다면, 우상향 호출
                assign_resource(MAP, 0, depth)
            elif di == 5:  # 하향이었다면, 좌하향 호출
                assign_resource(MAP, 2, depth)
            return False  # 정상적으로 자원 할당 안 됬으므로 False
    return True  # 정상적으로 자원할당 끝나면 True
 
def best_value(y, x):
    tmp = list(range(1, 6))
    for d in diff:
        ny, nx = y + d[0], x + d[1]
        if 0 <= ny < R and 0 <= nx < C:  # 모든 방향(6방향)에 대해 체크한 뒤
            if MAP[ny][nx] in tmp:  # 들어 있는 것은 tmp 에서 제거한다.
                tmp.remove(MAP[ny][nx])
    min_val = 9876543210
    min_val_idx = 0
    for t in tmp:  # tmp 에 있는 idx에서 가장 최소값을 구하고
        if cnt[t] < min_val:
            min_val = cnt[t]
            min_val_idx = t
    return min_val_idx  # 최소값의 가장 첫 index를 반환한다.
 
n = 10000
R = C = 5000
cnt = [9876543210] + [0] * (5)  # 각 인덱스가 몇개 쓰였는지 count
answer = [0, 1] + [0] * (n - 1)  # 자원값 저장하는 배열
MAP = [[0] * C for _ in range(R)]  # 이차원 배열 초기화
diff = ((-1, 1), (-1, -1), (1, -1), (1, 1), (-2, 0), (2, 0))  # 방향 및 검사에 쓰이는 dy, dx
y, x = R // 2, C // 2  # 원점 초기화
MAP[y][x] = 1  # 원점은 1
cnt[MAP[y][x]] += 1  # 1 갯수 증가
res_num = 2
idx = 0
while res_num != n + 1:
    sr = assign_resource(MAP, idx, res_num)  # 자원을 배치하고 bool 타입 결과 받음
    if sr:
        idx = (idx + 1) % 4  # True 일땐 방향을 바꿈
    else:
        pass  # False 일땐 방향 그대로
    res_num += 1
 
# for _ in range(int(input())):
#     print("here")
#     t = int(input())
#     print(answer[t])

for i in range(1, 830) :
    print(answer[i], end = ' ')