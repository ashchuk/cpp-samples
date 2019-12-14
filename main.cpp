#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//    int n;
//    std::string rawInput;
//    scanf("%d", &n);
//    std::cout << n << "!\n";
//    std::getline (std::cin, rawInput);
//    std::cout << rawInput << "!\n";
//    int numbers[n];
//    int i = 0;
//
//    vector<std::string> strings;
//    while( getline( cin, rawInput, ' ' ) )
//    {
//        strings.push_back(rawInput);
//    }
//
//    std::reverse(std::begin(strings), std::end(strings));
//    for (unsigned i=0; i<strings.size(); i++) {
//        std::cout << ' ' << strings.at(i);
//    }

//    int N,i=0;
//    cin>>N;
//    int *A = new int[N];
//    while(cin>>A[i++] && (i < N));
//    while(cout<<A[--N]<<' ' && N);
//    delete[] A;
//    return 0;

    int n, q, index, k = 0;
    std::cin >> n;
    std::cin >> q;
    vector<std::vector<int>> arrays;

    int i = 0;
    while (i != n) {
        int counter = 0;
        std::cin >> k;
        arrays.emplace_back();
        vector<int> test = arrays.at(i);

        while (counter < k) {
            int value;
            cin >> value;
            arrays.at(i).push_back(value);
            counter++;
        };
        i++;
    }

    int z = 0;
    while (z != n) {
        int c = 0;
        std::cin >> k;
        std::cin >> c;

        cout << arrays.at(k).at(c) << '\n';
        z++;
    }

    return 0;
}

class Complex {
public:
    int a, b;

    Complex(int r = 0, int i = 0) {
        a = r;
        b = i;
    }

    Complex operator+(Complex const &obj) {
        Complex result;
        result.a = a + obj.a;
        result.b = b + obj.b;
        return result;
    }

    void input(std::string input) {
        a = std::stoi(input.substr(0, input.find("+i")));
        b = std::stoi(input.substr(1, input.find("+i")));
    }

    friend ostream &operator<<(ostream &os, const Complex &complex);
};

ostream &operator<<(ostream &os, const Complex &complex) {
    os << complex.a << "+i" << complex.b;
    return os;
}

Complex operator+(Complex const &c1, Complex const &c2) {
    return Complex(c1.a + c2.a, c1.b + c2.b);
}

// or
//Complex operator+(Complex const &c1, Complex const &c2) {
//    Complex result;
//    result.a = c1.a + c2.a;
//    result.b = c1.b + c2.b;
//    return result;
//}

int overload_operators() {
    std::string first, second;
    std::string delimiter = "+i";

    std::cin >> first;
    std::cin >> second;

    Complex complex1 = Complex();
    Complex complex2 = Complex();

    complex1.a = std::stoi(first.substr(0, first.find(delimiter)));
    complex1.b = std::stoi(first.substr(1, first.find(delimiter)));
    complex2.a = std::stoi(second.substr(0, second.find(delimiter)));
    complex2.b = std::stoi(second.substr(1, second.find(delimiter)));

    Complex complex3 = complex1 + complex2;
    cout << complex3;
    return 0;
}

int overload_operators2()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}