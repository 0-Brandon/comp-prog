#include <bits/stdc++.h>

int main() {

    std::ios_base::sync_with_stdio(false);
     // First create an instance of an engine.
    std::random_device rnd_device;
    // Specify the engine and distribution.
    std::mt19937 mersenne_engine {rnd_device()};  // Generates random integers
    std::uniform_int_distribution<int> dist {1, 10};
    
    auto gen = [&](){
                   return dist(mersenne_engine);
               };

    std::vector<int> vec(10);
    std::generate(vec.begin(), vec.end(), gen);
    
    // Optional
    std::cout<<10<<'\n';
    for (const auto& i : vec) {
        std::cout << i << " ";
    }

    return 0;

}