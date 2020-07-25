//一个数是二的幂次吗
bool isanumberapoweroftwo(size_t num) {
    //return __builtin_popcountll(num)==1;
    return num != 0 && (num & -num)== num;
}