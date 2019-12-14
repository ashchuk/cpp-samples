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

    int n,q,index,k=0;
    std::cin>>n;
    std::cin>>q;
    vector<std::vector<int>> arrays;

    int i = 0;
    while (i != n) {
        int counter = 0;
        std::cin>>k;
        arrays.emplace_back();
        vector<int> test = arrays.at(i);

        while(counter < k){
            int value;
            cin>>value;
            arrays.at(i).push_back(value);
            counter++;
        };
        i++;
    }

    int z = 0;
    while (z != n) {
        int c = 0;
        std::cin>>k;
        std::cin>>c;

        cout<<arrays.at(k).at(c)<<'\n';
        z++;
    }

    return 0;
}
