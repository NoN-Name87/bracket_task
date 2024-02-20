#include <iostream>
#include <cstring>
#include <stack>

constexpr char SQUO_BRACKET = '[';
constexpr char FIGO_BRACKET = '{';
constexpr char ROUO_BRACKET = '(';
constexpr char SQUC_BRACKET = ']';
constexpr char FIGC_BRACKET = '}';
constexpr char ROUC_BRACKET = ')';
constexpr char ERROR = '!';
constexpr char SPACE = ' ';

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
// в прошлом коммите есть реализация с std::map<char, std::stack<char>>, но этот вероятнее самый лучший вариант
bool is_brackets_paired(const std::string & sqcs)
{
    std::stack<char> brackets;// better option
    for(const char & i : sqcs)
    {
        if(i == SPACE)
            continue;
        char temp = get_close_bracket(i);
        if(temp != ERROR)
        {
            brackets.push(temp);
        }
        else if(brackets.size() != 0 && brackets.top() == i)
        {
            brackets.pop();
        }
        else
        {
            return false;
        }
    }
    return brackets.size() == 0;
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