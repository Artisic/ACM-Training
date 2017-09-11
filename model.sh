#! /bin/sh

dirname=$1
name=$2
if [ $# != 2 ] ; then 
echo "USAGE: ./model.sh dirname projectname"  
exit 1; 
fi 

if [-d "$dirname"];then
echo "$dirname found..."
else
echo "$dirname not found..."
echo "mkdir $name..."
mkdir "$dirname"
fi
cd "$dirname"
if [ -d "$name" ]; then
echo "$name is existing..."
exit 1;
else
mkdir "$name"
cd "$name"
codefile=$name".cpp"
testfile=$name".txt"
objfile=$name".o"
makefile="Makefile"
touch $makefile
touch $codefile
touch $testfile
echo "a : $objfile
	g++ -o a $objfile 
$objfile : $codefile 
	g++ -c $codefile
.PHONY : clean
clean : 
	rm $objfile
">>$makefile
echo "#include<iostream>
#include<algorithm>
#include<cstdio>
#include<fstream>


using namespace std;
#define Debug
//************For Debug********
#ifdef Debug
ifstream fin(\"$testfile\");
#define in fin

#else
#define in cin
#endif
//******************************

int main()
{
    cout<<\"hello\"<<endl;
    return 0;
}

">>$codefile
vim $testfile
vim $codefile

fi
