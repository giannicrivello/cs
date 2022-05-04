#!/bin/bash
g++ -c -std=c++11 -stdlib=libc++ *.cpp -lstdc++
g++ -o bin hopPass.o shoppingCart.o
rm *.o
./bin  
rm bin