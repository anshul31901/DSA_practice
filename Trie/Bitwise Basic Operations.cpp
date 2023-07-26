int getXOR(int a, int b) {
    // Write Your Code Here
    return a^b;
}

int getBit(int c, int d) {
    // Write Your Code Here
  //we have to get cth bit of d
    return (d>>c)&1;
}

int setBit(int e, int f) {
    // Write Your Code Here
  //we have to set eth bit of f =1
    return (f|(1<<e));

}
