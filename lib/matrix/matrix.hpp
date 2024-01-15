#ifndef matrix_hpp
#define matrix_hpp

#include <iostream>

typedef unsigned long ul;
typedef long double ld;

template <class T = ld>
class Matrix {
    ul n, m;
    T **q;

    T **mMinor_j0(const ul __i, const ul __n, T **__A);
    void mMinor(T **__in, T **__out, const ul __i, const ul __j, const ul __n);

public:
    Matrix();
    Matrix(const ul _n);
    Matrix(const ul _n, const ul _m);
    Matrix(const Matrix &_m);
    ~Matrix();

    ul getN();

    ul getM();

    T get(const ul i, const ul j);

    void fill(const T d);

    void set(const ul i, const ul j, const T d);
    void set(T **__A);

    void input(std::istream &stream);
    void output(std::ostream &stream);

    class Element {
        T& _e;
    public:
        Element(T& _e) : _e(_e) {}
        Element& operator=(const T &__v) { _e = __v; return *this; }
        operator T() const { return _e; }
    };

    class Row {
        T *_q;
    public:
        Row(T *_q) : _q(_q) {}
        Element operator[](const ul j) { return Element(_q[j]); }
        Row& operator=(const T *&__v) { _q = __v; return *this; }
        operator T*() const { return _q; }
    };

    Row operator[](const ul i) {
        return Row(q[i]);
    }

    T &operator()(const ul i, const ul j);

    Matrix &operator=(const Matrix &__m);

    bool operator==(const Matrix &__m);
    bool operator!=(const Matrix &__m);

    Matrix operator+(const Matrix &__m);
    Matrix &operator+=(const Matrix &__m);

    template <class Ts = T>
    Matrix operator*(const Ts &__a);

    Matrix operator*(const Matrix &__m);

    template <class Ts = T>
    Matrix &operator*=(const Ts &__a);

    Matrix &operator*=(const Matrix &__m);

    Matrix &transpose();

    Matrix &identity();

    T det(T **__A, const ul __n);
    
    T determinant();

    Matrix inverse();
};

#endif /* matrix_hpp */
