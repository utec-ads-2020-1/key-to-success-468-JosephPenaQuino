#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>

#define mt std::vector<std::pair<char, int>>

bool sortbysec(const std::pair<char,int> &a, const std::pair<char,int> &b)
{ 
    return (a.second < b.second); 
} 


bool is_value_on_vector(mt &vec, char val)
{
    for (mt::iterator it = vec.begin(); it!=vec.end(); ++it)
        if (it->first==val)
            return true;
    return false;
}

void add_value_on_vector(mt &vec, char val)
{
    for (mt::iterator it = vec.begin(); it!=vec.end(); ++it)
        if (it->first==val)
            it->second++;
}

std::map<char, int> parse_(mt &vect)
{
    std::map<char, int> res;
    sort(vect.begin(), vect.end(), sortbysec);
    for (int i=0; i < vect.size(); ++i)
        res.insert(std::pair<char, int>(vect[i].first, vect.size()-i-1));
        // vect[i].second = i;
    return res;
}

std::vector<char> parse_v(mt &vect)
{
    std::vector<char> res;
    sort(vect.begin(), vect.end(), sortbysec);
    
    for (int i=0; i < vect.size(); ++i)
        res.push_back(vect[vect.size()-i-1].first);
    return res;
}

int main()
{
    int cases = 0;
    std::cin >> cases;
    bool first=true;

    for (int i=0; i < cases; ++i)
    {
        if (!first)
            std::cout << std::endl;
        first=false;
        std::vector<std::pair<char, int>> key_set;
        std::string word;
        // Read fist line
        std::cin >> word;

        // Save keys
        for (std::string::iterator it = word.begin(); it != word.end(); ++it)
        {
            if (!is_value_on_vector(key_set, *it))
                key_set.push_back(std::pair<char, int>(*it, 1));
            else
                add_value_on_vector(key_set, *it);
        }

        // Read second line
        mt words_set ;
        word.clear();
        std::cin >> word;


        for (std::string::iterator it = word.begin(); it != word.end(); ++it)
        {
            if (!is_value_on_vector(words_set, *it))
                words_set.push_back(std::pair<char, int>(*it, 1));
            else
                add_value_on_vector(words_set, *it);
        }

        std::map<char, int> ws = parse_(words_set);
        std::vector<char> parsed_keys_set = parse_v(key_set);
        // Write results
        for (std::string::iterator it = word.begin(); it != word.end(); ++it)
            std::cout << parsed_keys_set[ws[*it]];
        std::cout << std::endl;
    }
}
