#computing fib[n]
''' Seam Carving: 
resizing an dimageusing the seam-carving technique
You're making sur ethe main item or the person is not being 
squished until the very end whereas for the rest of the image
it can just be "gone'''

#you have pixels referring to the pixel in column x and row y, 
#with pixel (0,0) being the upper left corner. 
#Dual Gradient Energy Function. (will learn in calc)

#R(x, y) = (y, x+1) - 

a row of pixels with brightness going from 0 to 225. 

10 20 12 50 100 80 80 80 80 80
at what locations does the brightness change  a lot and where does it not. 
The change is a lot where the derivative is highest. 

f(x + 1) - f(x - 1)/2 is high?
f(x +1) - f(x-1) is an estimate for teh derivatives. 

10 20 12 50 100 80 80 80 80 80 80
10 20 12 50 100 80 90 90 90 80 80
10 20 12 50 100 80 90 90 90 80 80


f(y + 1) - f(y - 1)/ 2 is high?

at (x, y), is there a lot of change?

gradient(x, y): [
    f(x + 1) - f(x - 1) /2 #THE DERIVATIVE ALONG THE X-AXIS AND THE Y -AXIS. 
    f(y + 1) - f(y - 1)/ 2
]
#you might need to implmenet the partial derivatives. 

#you'll have to implement the sum of the energies (i think) in 
# the x, y and z axis for each of teh colours separately. 

#as you go from an area of left to right. 

#YOU want to first get rid of the darkest areas. 

#energies in a matrix form (dual gradient image. You want the
# sum of the energies to have the lowest sun and then get rid 
#of them. 
##You need to get the best array. 
#you do some diagonal sum thing I think... not too sure. )
# you don't want to distort the image. 

#you need to know the costs and how to get from one place to another and their costs. 



#how to get from one place... including teh one that you're looking at. 

#to get the smallest number, you need to look at the smallest
#cost from the bottom of the array.


#dynamic programming basically. 

