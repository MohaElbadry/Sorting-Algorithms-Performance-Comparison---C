#include <stdio.h>

int main(){
    remove("bubbledata(ord).txt");
    remove("bubbledata(rand).txt");
    remove("bubbledata(rev).txt");

    remove("insertiondata(ord).txt");
    remove("insertiondata(rand).txt");
    remove("insertiondata(rev).txt");

    remove("mergedata(ord).txt");
    remove("mergedata(rand).txt");
    remove("mergedata(rev).txt");

    remove("quickdata(ord).txt");
    remove("quickdata(rand).txt");
    remove("quickdata(rev).txt");

    remove("selectiondata(ord).txt");
    remove("selectiondata(rand).txt");
    remove("selectiondata(rev).txt");

    return 0;
}