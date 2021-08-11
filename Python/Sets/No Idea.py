# Enter your code here. Read input from STDIN. Print output to STDOUT
n, m = list(map(int, input().split()))
arr = list(map(int, input().split()))
A = set(map(int, input().split()))
B = set(map(int, input().split()))

happiness = 0
for item in arr:
    if item in A:
        happiness += 1
    elif item in B:
        happiness -= 1
        
print(happiness)
