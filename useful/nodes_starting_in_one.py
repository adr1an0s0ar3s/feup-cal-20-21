input = open(input(), "r")
output = open("result.txt", "w")

output.write(input.readline())

for line in input:
    temp = line.replace("(", " ")
    temp = temp.replace(", ", " ")
    temp = temp.replace(")", " ")
    a = temp.split()
    output.write(f"({int(a[0])+1}, {int(a[1])}, {int(a[2])})\n")