#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
#include <map>

constexpr char SQUO_BRACKET = '[';
constexpr char FIGO_BRACKET = '{';
constexpr char ROUO_BRACKET = '(';
constexpr char SQUC_BRACKET = ']';
constexpr char FIGC_BRACKET = '}';
constexpr char ROUC_BRACKET = ')';
constexpr char ERROR = '!';
constexpr char SPACE = ' ';
constexpr char EMPTY = 'E';

using Brackets = std::map<char, std::stack<char>>; 

char get_close_bracket(char bracket)
{
    char brack_type{};
    switch(bracket)
    {
        case SQUO_BRACKET:
            brack_type = SQUC_BRACKET;
            break;
        case FIGO_BRACKET:
            brack_type = FIGC_BRACKET;
            break;
        case ROUO_BRACKET:
            brack_type = ROUC_BRACKET;
            break;
        default:
            brack_type = ERROR;
    }
    return brack_type;
}

bool is_brackets_paired(const std::string & sqcs)
{
    Brackets bracks;
    char curr_brack{ERROR};
    for(const char & i : sqcs)
    {
        if(i == SPACE)
            continue;
        char temp = get_close_bracket(i);
        if(temp != ERROR)
        {
            curr_brack = temp;
            bracks[curr_brack].push(i);
        }
        else if((curr_brack == EMPTY || curr_brack == i) && bracks[i].size())
        {
            bracks[i].pop();
            curr_brack = EMPTY;    
        }
        else
            return false;
    }
    auto iter = std::find_if(bracks.cbegin(), bracks.cend(), [](auto & brack){ return brack.second.size(); });
    return iter == bracks.cend();
}

int main(int argc, char **argv)
{
    std::string sqcs{""};
    try
    {
        if(argc > 1)
        {
            for(size_t i = 1; i < argc; i++)
            {
                sqcs += std::string(argv[i]);
            }
        }
        else
        {
            std::cout << "Enter bracket sequence:\n";
            std::getline(std::cin, sqcs); 
        }
        if(is_brackets_paired(sqcs))
            std::cout << "yes\n";
        else
            std::cout << "no\n"; 
    }
    catch(const std::exception & expect)
    {
        std::cout << expect.what() << "\n";
    }    
    return 0;
}