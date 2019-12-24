import os


if __name__ == '__main__':
	os.chdir("./DataProcess/")
	a = os.system("execute")
	f = open("../Data/count.txt")
	count = int(f.readline())
	f.close()
	os.chdir("../Visualization/ClasterVisualizer/")
	os.system("java ClasterVisualizer")
	os.chdir("../BoundaryVisualizer/")
	for i in range(count):
		os.system("java BoundaryVisualizer " + str(i))
