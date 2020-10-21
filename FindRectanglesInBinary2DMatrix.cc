/*
FindRectanglesInBinary2DMatrix:a C++ program to find and draw all rectangles containing only 0s in a binary 2D Matrix and return their areas, heights and widths.
developed by Jaafar EL Bakkali (bahmedj@gmail.com).
* Copyright (C) 2019-2020 Jaafar EL Bakkali
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h> 
#include <iterator>
#include <stdlib.h>
#include <cstddef> 
#include <list> 
#include <bits/stdc++.h>
#include <algorithm>   
using namespace std;
int
    skip               = 1,
    minw               = 0,
    it                 = 0,
    area               = 0,
    previousarea       = 0,
    area_max           = 0,
    Corner_point_1_i   = 0,
    Corner_point_1_j   = 0,
    Corner_point_2_i   = 0,
    Corner_point_2_j   = 0,
    Corner_point_3_i   = 0,
    Corner_point_3_j   = 0,
    Corner_point_4_i   = 0,
    Corner_point_4_j   = 0,
    Rect_ID            = 0;
bool 
    activate           = true;
vector<vector<int> > 
                         binary_matrix, 
                         original_binary_matrix, 
                         stack_1,
                         stack_2;

/*<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>*/
void ReadMatrixData(std::string file, int numberOfColumns) {
int i=0, j=0;
ifstream inFile;
inFile.open(file);
vector<string> data;
stringstream strStream;
strStream << inFile.rdbuf();
string str = strStream.str();
string buf;                 
stringstream ss(str);      
vector<string> tokens; 
while (ss >> buf)
{
tokens.push_back(buf);
}

vector<int> vec;  
for (int l=0; l< tokens.size(); l++)
{
int val = stoi(tokens[l]);
if (i< numberOfColumns) {
i++; vec.push_back(val);} else {i=0; binary_matrix.push_back( vec);vec.clear();};
}
cout<< "Read binary matrix.................Ok"<< endl;
}

/*<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>*/
void CalculateRectangleAreas(){
activate=true;
for (int i = 0; i < binary_matrix.size(); i++)
{//1 
for (int j = 0; j < binary_matrix[i].size(); j++)  
{//2
if( binary_matrix[i][j] ==skip) { continue; };
if (i==0) { stack_2[i][j]=1;} else {stack_2[i][j]=stack_2[i-1][j]+1; };
if (j==0) { stack_1[i][j]=1;} else {stack_1[i][j]=stack_1[i][j-1]+1; minw=stack_1[i][j];}
for (int it=0; it< stack_2[i][j]; it++) 
{//3
minw = min(minw, stack_1[i-it][j]);
area = (it+1)*minw;
if (area >area_max)
{//4
area_max = area; 
 Corner_point_1_j=i-it;
 Corner_point_1_i=j-minw+1 ;
 Corner_point_2_j=i;
 Corner_point_2_i=j;
 Corner_point_3_j=i-it;
 Corner_point_3_i=j ;
 Corner_point_4_j=i;
 Corner_point_4_i=j-minw+1;
};//4
}//3
}//2 
}//1
if (area>= 2) 
 {
previousarea= area;
cout << " Area of the Rectangle N°: "<< Rect_ID++  <<  ", is: "<<area_max << endl;
cout << " Height and width of the rectangle: ("  << Corner_point_2_j-Corner_point_1_j+1 << "," <<Corner_point_2_i-Corner_point_1_i+1<< ")"<<endl;
cout << " Corner point 1 = ("  << Corner_point_1_i << " , "  << Corner_point_1_j<< ") ; Corner point 2  (" << Corner_point_2_i  << " , " << Corner_point_2_j  << ")"<<   endl;
cout << " Corner point 3 = ("  << Corner_point_3_i << " , "  << Corner_point_3_j<< ") ; Corner point 4  (" << Corner_point_4_i  << " , " << Corner_point_4_j  << ")"<<   endl;
// Displaying rectangle in colored fashion .
for (int i = 0; i < binary_matrix.size(); i++)
{ 
cout<< "\t";
for (int j = 0; j < binary_matrix[i].size(); j++) 
{
if (  i>=Corner_point_1_j  and i<=Corner_point_2_j and j>=Corner_point_4_i  and j<=Corner_point_3_i ) {
cout <<"\033[1;31m"<< original_binary_matrix[i][j]<<"\033[1;0m";
 } else {
cout << original_binary_matrix[i][j];
}
}
cout << endl;
} 

}
for (int i = Corner_point_1_j; i < Corner_point_2_j +1; i++)
{ 
for (int j = Corner_point_4_i; j < Corner_point_3_i+1; j++) 
{
binary_matrix[i][j]=skip ; 
}

} 
cout << endl;
}

/*<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>*/
int main( int argc, char* args[] )



{// main


cout <<"\033[1;35m"<< " \n======================================================================================================\n==FindRectanglesInBinary2DMatrix, a C++ program to find and draw all rectangles \n==containing only 0s in a binary 2D Matrix and return their areas, heights and widths.\n ==developed by Jaafar EL Bakkali (bahmedj@gmail.com). \n======================================================================================================\n"<<"\033[1;0m";


ReadMatrixData(args[1], stoi(args[2]));
// show original matrix
for (int i = 0; i < binary_matrix.size(); i++)
{ 

for (int j = 0; j < binary_matrix[i].size(); j++) 
{
cout<<  binary_matrix[i][j];
}
cout << endl;
}

original_binary_matrix= binary_matrix;
stack_1 =binary_matrix;
stack_2 =binary_matrix;

for (int i = 0; i < binary_matrix.size(); i++)
{ 

for (int j = 0; j < binary_matrix[i].size(); j++) 
{
stack_1[i][j]=0;
stack_2[i][j]=0;
}}


while (previousarea>0 or activate==true) {
activate=false;
 minw=0;
 it=0;
 area=0;
 area_max=0;
 Corner_point_1_i=0;
 Corner_point_1_j=0;
 Corner_point_2_i=0;
 Corner_point_2_j=0;
 Corner_point_3_i=0;
 Corner_point_3_j=0;
 Corner_point_4_i=0;
 Corner_point_4_j=0;
 area= 0; 

for (int i = 0; i < binary_matrix.size(); i++)
{ 

for (int j = 0; j < binary_matrix[i].size(); j++) 
{
stack_1[i][j]=0;
stack_2[i][j]=0;
}}
CalculateRectangleAreas();
if (area<2) break;}
cout <<"\033[1;31m"<< "\n Good bye.\n"<<"\033[1;0m";
}// main
