import os


if __name__ == '__main__':
	count = os.system(".\\DataProcess\\execute")
	os.chdir("./Visualization/ClasterVisualizer/")
	os.system("java ClasterVisualizer")
	os.chdir("../BoundaryVisualizer/")
	for i in range(count):
		os.system("java BoundaryVisualizer " + str(i))
