import matplotlib.pyplot as plt
data = []
dim = [1,2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90,100]
for i in range(0,19):
    
    with open("..\Clustering-EuDistance\DATA_DIM_"+str(i)+".txt") as dat:
        lines = dat.read().split(' ')
    for j in lines:
        if j.isdigit():
            data.append(float(j))

    plt.hist(data) 
    plt.xlabel("Data")
    plt.ylabel("Clustering")
    plt.title("Dimension " + str(dim[i]))
    plt.savefig("Images\DATA_DIM_"+str(i)+".png")
    plt.close()
    
    data = []
