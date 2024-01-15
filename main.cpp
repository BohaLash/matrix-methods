#include <iostream>
#include "lib/matrix/matrix.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    Matrix<long double> A(n);
    A.input(cin);
    A = A.inverse();
    A.output(cout);
    return 0;
}
