#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;


//int main() {
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

//    int n, q, index, k = 0;
//    std::cin >> n;
//    std::cin >> q;
//    vector<std::vector<int>> arrays;
//
//    int i = 0;
//    while (i != n) {
//        int counter = 0;
//        std::cin >> k;
//        arrays.emplace_back();
//        vector<int> test = arrays.at(i);
//
//        while (counter < k) {
//            int value;
//            cin >> value;
//            arrays.at(i).push_back(value);
//            counter++;
//        };
//        i++;
//    }
//
//    int z = 0;
//    while (z != n) {
//        int c = 0;
//        std::cin >> k;
//        std::cin >> c;
//
//        cout << arrays.at(k).at(c) << '\n';
//        z++;
//    }
//
//    return 0;
//}
//
//class Complex {
//public:
//    int a, b;
//
//    Complex(int r = 0, int i = 0) {
//        a = r;
//        b = i;
//    }
//
//    Complex operator+(Complex const &obj) {
//        Complex result;
//        result.a = a + obj.a;
//        result.b = b + obj.b;
//        return result;
//    }
//
//    void input(std::string input) {
//        a = std::stoi(input.substr(0, input.find("+i")));
//        b = std::stoi(input.substr(1, input.find("+i")));
//    }
//
//    friend ostream &operator<<(ostream &os, const Complex &complex);
//};
//
//ostream &operator<<(ostream &os, const Complex &complex) {
//    os << complex.a << "+i" << complex.b;
//    return os;
//}
//
//Complex operator+(Complex const &c1, Complex const &c2) {
//    return Complex(c1.a + c2.a, c1.b + c2.b);
//}
//
//// or
////Complex operator+(Complex const &c1, Complex const &c2) {
////    Complex result;
////    result.a = c1.a + c2.a;
////    result.b = c1.b + c2.b;
////    return result;
////}
//
//int overload_operators() {
//    std::string first, second;
//    std::string delimiter = "+i";
//
//    std::cin >> first;
//    std::cin >> second;
//
//    Complex complex1 = Complex();
//    Complex complex2 = Complex();
//
//    complex1.a = std::stoi(first.substr(0, first.find(delimiter)));
//    complex1.b = std::stoi(first.substr(1, first.find(delimiter)));
//    complex2.a = std::stoi(second.substr(0, second.find(delimiter)));
//    complex2.b = std::stoi(second.substr(1, second.find(delimiter)));
//
//    Complex complex3 = complex1 + complex2;
//    cout << complex3;
//    return 0;
//}
//
//int overload_operators2() {
//    Complex x, y;
//    string s1, s2;
//    cin >> s1;
//    cin >> s2;
//    x.input(s1);
//    y.input(s2);
//    Complex z = x + y;
//    cout << z << endl;
//}

struct Workshops {
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops {
    int n;
    vector <Workshops> w;
};

Available_Workshops *initialize(int *start_time, int *duration, int n) {
    Available_Workshops *paw=new(Available_Workshops);
    Workshops ws;

    paw->n=n;
    for (int i=0;i<n;i++) {
        //construct a Workshops
        ws.start_time=start_time[i];
        ws.duration=duration[i];
        ws.end_time=start_time[i]+duration[i];
        paw->w.push_back(ws);
    }

    return paw;
}

bool compare(Workshops w1, Workshops w2) {
    return (w1.end_time < w2.end_time);
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
    // sort workshops by end_time
    sort(ptr->w.begin(),ptr->w.end(),compare);

    // interval scheduling
    int last_processed_time=-1;
    int maxWorkshops=0;
    for (int i=0;i<ptr->n;i++) {
        if (ptr->w[i].start_time >= last_processed_time) {
            last_processed_time=ptr->w[i].end_time;
            maxWorkshops++;
        }
    }

    return maxWorkshops;
}


struct Workshop {
    int start_time;
    int end_time;

    bool operator <(const Workshop &a) const
    {
        if (end_time != a.end_time) return (end_time < a.end_time);
        return (start_time < a.start_time);
    }
};

//struct Available_Workshops {
//    int n;
//    Workshop *workshops = new Workshop[n];
//};
//
//Available_Workshops *initialize(const int start_time[], const int duration[], int number) {
//    auto* result = new Available_Workshops();
//    result->n = number;
//    result->workshops = new Workshop[number];
//    for (int i = 0; i == number; i++) {
//        result->workshops->start_time = start_time[i];
//        result->workshops->end_time = start_time[i]+duration[i];
//    }
//    return result;
//}
//
//string CalculateMaxWorkshops(Available_Workshops *availableWorkshops) {
//    sort(availableWorkshops->workshops, availableWorkshops->workshops+availableWorkshops->n);
//
//    int ret = 1;
//    int currentEnd = availableWorkshops->workshops[0].end_time;
//
//    for (int i=1;i<availableWorkshops->n;i++)
//    {
//        if (availableWorkshops->workshops[i].start_time >= currentEnd)
//        {
//            currentEnd = availableWorkshops->workshops[i].end_time;
//            ret++;
//        }
//    }
//
//    return std::to_string(ret);;
//}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int *start_time = new int[n];
    int *duration = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> duration[i];
    }

    Available_Workshops *ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}

enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

template<> struct Traits<Fruit>
{
    static string name(int index) {
        if (index == 0){
            return "apple";
        }
        if (index == 1){
            return "orange";
        }
        if (index == 2){
            return "pear";
        }
        return "unknown";
    }
};
template<> struct Traits<Color>
{
    static string name(int index) {
        if (index == 0){
            return "red";
        }
        if (index == 1){
            return "green";
        }
        if (index == 2){
            return "orange";
        }
        return "unknown";
    }
};

// Define specializations for the Traits class template here.


int test()
{
    int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}