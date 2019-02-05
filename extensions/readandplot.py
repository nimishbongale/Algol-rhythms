import matplotlib.pyplot as plt

file1 = open("file.txt", "r+")
info = file1.readlines()
X = []
Y = []
for i in range(len(info)):
    word = info[i].split()
    X.append(float(word[0]))
    Y.append(float(word[1]))

fig = plt.figure()
plt.plot(X, Y)
plt.show()
