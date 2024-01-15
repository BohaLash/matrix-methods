#include <iostream>
#include "matrix.hpp"

template <class T>
Matrix<T>::Matrix() {
    n = m = 0;
}

template <class T>
Matrix<T>::Matrix(const ul _n) : Matrix<T>::Matrix(_n, _n) {}

template <class T>
Matrix<T>::Matrix(const ul _n, const ul __m) : n(_n), m(__m) {
    q = new T*[n];
    for (ul i = 0; i < n; ++i)
        q[i] = new T[m];
}

template <class T>
Matrix<T>::Matrix(const Matrix<T>& __m) {
    ul i, j;
    if (n != __m.n || m != __m.m) {
        for (i = 0; i < m; ++i)
            delete [] q[i];
        delete [] q;
        n = __m.n;
        m = __m.m;
        q = new T*[n];
        for (i = 0; i < n; ++i) {
            q[i] = new T[m];
            for (j = 0; j < m; ++j)
                q[i][j] = __m.q[i][j];
        }
    } else {
        for (i = 0; i < n; ++i)
            for (j = 0; j < m; ++j)
                q[i][j] = __m.q[i][j];
    }
}

template <class T>
Matrix<T>::~Matrix() {
    for (ul i = 0; i < m; ++i) delete [] q[i];
    delete [] q;
}

template <class T>
ul Matrix<T>::getN() {
    return n;
}

template <class T>
ul Matrix<T>::getM() {
    return m;
}

template <class T>
T Matrix<T>::get(const ul i, const ul j) {
    return q[i][j];
}

template <class T>
void Matrix<T>::fill(const T d) {
    ul i, j;
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            q[i][j] = d;
}

template <class T>
void Matrix<T>::set(const ul i, const ul j, const T d) {
    q[i][j] = d;
}

template <class T>
void Matrix<T>::set(T **__A) {
    ul i, j;
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            q[i][j] = __A[i][j];
}

template <class T>
void Matrix<T>::input(std::istream& stream) {
    ul i, j;
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            stream >> q[i][j];
}

template <class T>
void Matrix<T>::output(std::ostream& stream) {
    ul i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m - 1; ++j)
            stream << q[i][j] << ' ';
        stream << q[i][m - 1] << '\n';
    }
}

template <class T>
T& Matrix<T>::operator()(const ul i, const ul j) {
    return q[i][j];
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& __m) {
    ul i, j;
    n = __m.n;
    m = __m.m;
    q = new T*[n];
    for (i = 0; i < n; ++i) {
        q[i] = new T[m];
        for (j = 0; j < m; ++j)
            q[i][j] = __m.q[i][j];
    }
    return *this;
}

template <class T>
bool Matrix<T>::operator==(const Matrix<T>& __m) {
    if (n != __m.n || m != __m.m) return false;
    ul i, j;
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            if (q[i][j] != __m.q[i][j])
                return false;
    return true;
}

template <class T>
bool Matrix<T>::operator!=(const Matrix<T>& __m) {
    return !(*this == __m);
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& __m) {
    if (n != __m.n || m != __m.m) return *this;
    Matrix<T> B = *this;
    ul i, j;
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            B(i, j) += __m.q[i][j];
    return B;
}

template <class T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& __m) {
    if (n != __m.n || m != __m.m) return *this;
    ul i, j;
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            this -> q[i][j] += __m.q[i][j];
    return *this;
}

template <class T>
template <class Ts>
Matrix<T> Matrix<T>::operator*(const Ts& __a) {
    ul i, j;
    Matrix<T> B = *this;
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            B.q[i][j] *= __a;
    return B;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& __m) {
    if (m != __m.n) return *this;
    Matrix<T> B(n, __m.m);
    ul i, j, k;
    for (i = 0; i < n; ++i)
        for (j = 0; j < __m.m; ++j)
            for(k = B.q[i][j] = 0; k < m; ++k)
                B.q[i][j] += q[i][k] * __m.q[k][i];
    return B;
}

template <class T>
template <class Ts>
Matrix<T>& Matrix<T>::operator*=(const Ts& __a) {
    ul i, j;
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            q[i][j] *= __a;
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& __m) {
    if (m != __m.n) return *this;
    Matrix<T> B(n, __m.m);
    ul i, j, k;
    for (i = 0; i < n; ++i)
        for (j = 0; j < __m.m; ++j)
            for(k = B.q[i][j] = 0; k < m; ++k)
                B.q[i][j] += q[i][k] * __m.q[k][i];
    *this = B;
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::transpose() {
    Matrix<T> B(m, n);
    ul i, j;
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            B.q[j][i] = q[i][j];
    *this = B;
    B.~Matrix();
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::identity() {
    ul i, j;
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            q[i][j] = (i == j);
    return *this;
}

template <class T>
T **Matrix<T>::mMinor_j0(const ul __i, const ul __n, T **__A) {
    ul i = 0;
    T **B;
    B = new T *[__n];
    for (; i < __n; ++i)
        B[i] = __A[i + (i >= __i)] + 1;
    return B;
}

template <class T>
T Matrix<T>::det(T **__A, const ul __n) {
    if (__n == 1) return __A[0][0];
    if (__n == 2) return __A[0][0] * __A[1][1] - __A[0][1] * __A[1][0];
    ul i = 0;
    T res = 0;
    for (; i < __n; ++i)
        res += (1 - 2 * (bool)(i & 1)) * __A[i][0] * det(mMinor_j0(i, __n - 1, __A), __n - 1);
    return res;
}

template <class T>
T Matrix<T>::determinant() {
    return (n == m) * det(q, n);
}

template <class T>
void Matrix<T>::mMinor(T **__in, T **__out, const ul __i, const ul __j, const ul __n) {
    ul i, j;
    for (i = 0; i < __n; ++i)
        for (j = 0; j < __n; ++j)
            __out[i][j] = __in[i + (i >= __i)][j + (j >= __j)];
}

template <class T>
Matrix<T> Matrix<T>::inverse() {
    ul i, j;
    T **M;
    Matrix<T> B(n);
    M = new T *[n - 1];
    for (i = 0; i < n; ++i)
        M[i] = new T [n - 1];
    T d = det(q, n);
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            mMinor(q, M, i, j, n - 1);
            B.q[j][i] = (1 - 2 * (bool)((i + j) & 1)) * det(M, n - 1) / d;
        }
    }
    return B;
}
