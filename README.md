# MillikanAnalysis
This is a C++ program based upon the RooT library which analyses the data set of the charges of the drops measured during the Millikan experiment returnig the graph of the trend of the variance given by the function S(q), the best value from the set and some statistical data. 

The local minimum in the neighbourhood of 1.6021e-19 is the best value for the data set.
In this neighbourhood you will found a parabola like shape, the minimun refers to this section of the graph.
The deviation in sigma is only in term of statistical error.

REQUIREMENTS

RooT release 6.14/04

In this repository you wìll find a makefile, two *.cxx* files and one *.h* file.

MAKEFILE

The commands without the quotation mark are:

"all" wich compiles the program, outputting an executable called "millikan"
"clean" wich removes all the .o files and wipes the core

USING OF "MILLIKAN"

In Linux and Linux-like terminals, you execute the program by typing

./millikan *nameoffile* *startingpoint* *widthofbin* *numberofbin*

In wich:

nameoffile is the name, with eventual extension, of the file in wich you have ONLY the values of the charges;
startingpoint is the x point, so the starting test charge, from which the computer starts computing the values of S(q);
widthofbin is the amount by which the x is incremented for every iteration;
numberofbin is the amount of iterations you want.

The final x point is then given by 

startingpoint + (widthofbin * numberofbin)

Thank you for your attention.

ANDREA TREZZI
