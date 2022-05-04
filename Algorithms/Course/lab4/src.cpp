#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<cassert>

#define TESTING


uint32_t hash(const std::string& pattern, uint32_t q){
    uint32_t p_len = pattern.length();

    uint32_t h = 0;
    uint32_t b = 10;

    for (size_t i = 0; i < p_len; ++i)
        h += (h * b + int(pattern[i])) % q;

    return h;
}

std::vector<uint32_t> RabinKarpSearch(const std::string& Text, const std::string& Pattern){
    uint32_t t_len = Text.length();
    uint32_t p_len = Pattern.length();

    std::vector<uint32_t> result;

    uint32_t q = 997;
    uint32_t p_hash = hash(Pattern, q);

    for (size_t i = 0; i <= t_len - p_len; ++i){
        std::string tmp;
        for (size_t j = i; j < i + p_len; ++j){
            tmp.push_back(Text[j]);
        }
        if (p_hash == hash(tmp, q)){
            for (size_t k = 0; k < p_len && Pattern[k] == tmp[k]; ++k)
                if (k == p_len - 1)
                    result.push_back(i);
        }
    }
    return result;
    
}


void test(const std::vector<std::pair<std::pair<std::string, std::string>, std::vector<uint32_t>>>& testCases){
    
    for (size_t i = 0; i < testCases.size(); ++i){
        std::cout << "Test#" << i+1 << ":" << std::endl;
        std::cout << "Pattern - " << testCases[i].first.first << ", text - " << testCases[i].first.second << " ==> ";
        assert(RabinKarpSearch(testCases[i].first.second, testCases[i].first.first) == testCases[i].second && "Error!");
        std::cout << " Correct!" << std::endl;
    }
    
}


int main(){

#ifdef TESTING
    test({{{"bra", "abracadabra"}, {1, 8}},
          {{"Iron", "Iron man has the best Iron suite."}, {0, 22}},
          {{"text", "this text is just text."}, {5, 18}},
          {{"something", "in this sentense there arent patterns..."}, {}}
        });
    return 0;
#endif

    std::string text, pattern;
    std::getline(std::cin, pattern);
    std::getline(std::cin, text);

    std::vector<uint32_t> result = RabinKarpSearch(text, pattern);
    for (auto& el: result)
        std::cout << el << " ";
    std::cout << std::endl;


    return 0;
}