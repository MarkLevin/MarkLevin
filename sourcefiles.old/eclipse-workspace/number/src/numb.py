from numpy import *
from matplotlib.pyplot import *

x = linspace(0, 2*pi, 100)
y = sin(x)
plot(x, y) # call Matplotlib plotting function
show()