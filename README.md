# MillikanAnalysis
This is a C++ program based upon the RooT library which analyses the data set of the charges of the drops measured during the Millikan experiment returnig the graph of the trend of the variance given by the function S(q), the best value from the set and some statistical data. 

The local minimum in the neighbourhood of 1.6021e-19 is the best value for the data set.
In this neighbourhood you will found a parabola like shape, the minimun refers to this section of the graph.
The deviation in sigma is only in term of statistical error.

This is the second update, I rewrote the code in form of classes to better manage the memory and to reduce the computing power required, making this version faster.

*********************************************************************************************************************************

REQUIREMENTS

RooT release 6.14/04

*********************************************************************************************************************************

In this repository you wìll find a makefile, three *.cxx* files, two *.h* file and two *.dat* test file.

The test file "vitto.dat" contains a series of fake charge values which return a parabola having a minimun in 1.60438e-19 at maximun precision.

You can test the software with this data set, varying the range and the precision.

3.dat are my personal laboratory datas, you can see the parabola minimum in a small neighbourhood of 1.61708e-19.

I suggest not to exceed with the number of iterations, I personally use around 20.000~100.000 iterations. 
I saw the statistical procedure goes up to 2.000.000 and probably more iterations, but the precision doesn't increase and RooT just stops working above 150.000 iterations.

MAKEFILE

The commands without the quotation mark are:

"all" which compiles the program, outputting an executable called "Millikan".

"clean" which removes all the .o files and wipes out the core.

*********************************************************************************************************************************

USE OF "MILLIKAN"

In Linux and Linux-like terminals, you execute the program by typing

./Millikan *"name of file"* *"starting point"* *"width of bin"* *"num of bin"*

In which:

"name of file" is the name, with eventual extension, of the file in which you have ONLY the values of the charges;

"starting point" is the x point, so the starting test charge, from which the computer starts computing the values of S(q);

"width of bin" is the amount by which the x is incremented for every iteration;

"num of bin" is the amount of iterations you want.

*********************************************************************************************************************************
HOW TO CALCULATE THE FINAL POINT OF THE GRAPH

The final x point is then given by:

startingpoint + (widthofbin * numbofbin)

I'm sorry if that is not the most efficient and easy way, I will update in future: any suggestion is appreciated.

*********************************************************************************************************************************
EXIT CODES

To see an exit code, type *echo $?* in the terminal.

I assigned various exit commands, their return are:

1 = Generic error, probably  wrong input type or too much iterations asked.

2 = The amount of files required was not met, you inserted more or less than 5 elements, which is the number currently required.

3 = The file you specified does not exist.

130 = Program closed with "Ctrl+C".

*********************************************************************************************************************************
Thank you for your attention, I hope you will appreciate my work.

Andrea Trezzi 

Special thanks to TheElegantTurtle, who helped me in debugging :)

Milan, 22nd November 2018
