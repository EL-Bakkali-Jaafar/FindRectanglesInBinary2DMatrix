# FindRectanglesInBinary2DMatrix
a C++ program to find and draw all rectangles containing binary sub-matrices with all 0s and return their areas, heights and widths.
This C++ program uses Largest Rectangular Area In Histogram Algorithm and it is inspired from a python-3 version written by tommy carstensen ( https://stackoverflow.com/a/30418912).

To compile the program, only to do is to open new Linux terminal and put the following command:<br>
g++ -O2  FindRectanglesInBinary2DMatrix.cc -o  FindRectanglesInBinary2DMatrix

To run the program, you should type:<br>
./FindRectanglesInBinary2DMatrix 2dbinarymatrix_file.txt  numberOfColumns<br>

Here a demonstrative example, the file 2dbinary_matrix.txt contains the following matrix:<br>

1 0 0 0 0 0 1<br>
0 0 0 0 0 0 1<br>
1 1 0 0 0 0 1<br>
0 1 1 1 0 0 0<br>
0 1 1 1 0 0 0<br>
1 1 1 0 0 1 1<br>
1 1 1 0 0 1 1<br>
0 0 1 1 1 1 1<br>

As we can see the number of columns is 7 whereas the number of rows is 8.

./FindRectanglesInBinary2DMatrix 2dbinary_matrix.txt  7<br>

Afte execution, the output of the program will be as follows:<br>

    <img src=" https://raw.githubusercontent.com/EL-Bakkali-Jaafar/FindRectanglesInBinary2DMatrix/main/pic1.png" />

![alt text](https://raw.githubusercontent.com/EL-Bakkali-Jaafar/FindRectanglesInBinary2DMatrix/main/pic2.png
?raw=true)

