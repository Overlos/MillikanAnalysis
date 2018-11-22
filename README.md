# MillikanAnalysis
This is a C++ program based upon the RooT library which analyses the data set of the charges of the drops measured during the Millikan experiment returnig the graph of the trend of the variance given by the function S(q), the best value from the set and some statistical data. 

The local minimum in the neighbourhood of 1.6021e-19 is the best value for the data set.
In this neighbourhood you will found a parabola like shape, the minimun refers to this section of the graph.
The deviation in sigma is only in term of statistical error.

*********************************************************************************************************************************

REQUIREMENTS

RooT release 6.14/04

*********************************************************************************************************************************

In this repository you wìll find a makefile, two *.cxx* files and one *.h* file.

MAKEFILE

The commands without the quotation mark are:

"all" which compiles the program, outputting an executable called "Millikan".

"clean" which removes all the .o files and wipes out the core.

*********************************************************************************************************************************

USE OF "MILLIKAN"

In Linux and Linux-like terminals, you execute the program by typing

./Millikan *"name of file"* *"starting point"* *"width of bin"* *"num of bin"*

In wich:

"name of file" is the name, with eventual extension, of the file in wich you have ONLY the values of the charges;

"starting point" is the x point, so the starting test charge, from which the computer starts computing the values of S(q);

"width of bin" is the amount by which the x is incremented for every iteration;

"num of bin" is the amount of iterations you want.

*********************************************************************************************************************************
HOW TO CALCULATE THE FINAL POINT OF THE GRAPH

The final x point is then given by:

startingpoint + (widthofbin * numbofbin)

I'm sorry if that is not the most efficient and easy way, I will update in future: any suggestion is appreciated.

*********************************************************************************************************************************
ERROR CODES

I assigned various exit commands, their return are:

0 = The file you specified does not exist.

1 = The amount of files required was not met, you inserted more or less than 5 elements, which is the number currently required.

*********************************************************************************************************************************
Thank you for your attention, I hope you will appreciate my work.

Andrea Trezzi 

Milan, 22nd November 2018
