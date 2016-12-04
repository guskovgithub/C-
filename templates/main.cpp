// Шаблоны: класс размерной величины
// !!!  ВЫПОЛЕНЫ ВСЕ УПРАЖНЕНИЯ !!!

#include <iostream>

//Упражнение 1
//        метр килограмм секунда ампер кельвин моль кандела
//Упражнение 3,4,5
//Перегрузка операторов
template<int L, int M, int T, int I, int K, int N, int J>
class DimQ {
    double value;
public:
    DimQ(double data) { value = data; }

    double get() {
     return value;
    }

    //Перегрузка операторов
    DimQ<L, M, T, I, K, N, J> operator-() {
     return DimQ<L, M, T, I, K, N, J>(-value);
    }

    DimQ<L, M, T, I, K, N, J> operator+(DimQ<L, M, T, I, K, N, J> &other) {
     return DimQ<L, M, T, I, K, N, J>(value + other.get());
    }


    DimQ<L, M, T, I, K, N, J> operator-(DimQ<L, M, T, I, K, N, J> &other) {
     return DimQ<L, M, T, I, K, N, J>(value - other.get());
    }

    template<int L1, int M1, int T1, int I1, int K1, int N1, int J1>
    DimQ<L + L1, M + M1, T + T1, I + I1, K + K1, N + N1, J + J1> operator*(DimQ<L1, M1, T1, I1, K1, N1, J1> other) {
     return DimQ<L + L1, M + M1, T + T1, I + I1, K + K1, N + N1, J + J1>(value + other.get());
    }

    template<int L1, int M1, int T1, int I1, int K1, int N1, int J1>
    DimQ<L - L1, M - M1, T - T1, I - I1, K - K1, N - N1, J - J1> operator/(DimQ<L1, M1, T1, I1, K1, N1, J1> other) {
     return DimQ<L - L1, M - M1, T - T1, I - I1, K - K1, N - N1, J - J1>(value / other.get());
    }

    friend  std::ostream &operator<<(std::ostream &os, DimQ<L, M, T, I, K, N, J> &object) {
     os << object.get() << " " << " метр^" << L << " килограмм^" << M << " секунда^" << T << " ампер^" << I
        << " кельвин^" << K << " моль^" << N << " кандела^" << J;
     return os;
    }
};


//Упражнение 2
//Создайте псевдонимы типов для скорости, ускорения, а так же безразмерной величины.

typedef DimQ<1,0,0,0,0,0,0> Length;
typedef DimQ<1,0,-1,0,0,0,0> Velocity;
typedef DimQ<1,0,-2,0,0,0,0> Acceleration;
typedef DimQ<0,0,0,0,0,0,0> Nondim;
typedef DimQ<0,0,1,0,0,0,0> Time;

int main() {

//Упражнение 6 и 7
//Проверка работы программы
// Длина
Length l = {100};
// Время
Time t = {20};

// Скорость
Velocity v = l / t;

// Ускорение
Acceleration a = v / t;
std::cout << a << std::endl;

// Размерная величина
auto smth = v*a*a/t;
// Безразмерная величина
auto dimensionless = v/v;

// Ошибка компиляции!
// Dimensionless d = v;
// Mass m = v;
// Amount a = d;

    std::cout << smth << std::endl;
    std::cout << dimensionless << std::endl;
 return 0;
};