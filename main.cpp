#include <iostream>
#include <cstring>

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

int is_bracket_paired(const std::string & sqcs, size_t index, char brack_type) // checked only one sequence
{
    for(index; index < sqcs.size(); index++)
    {
        char bracket = get_close_bracket(sqcs[index]);
        if(sqcs[index] == SPACE)
            continue;
        if(sqcs[index] == brack_type)
            break;
        else if(bracket != ERROR)
            index = is_bracket_paired(sqcs, index + 1, bracket);
        else
            index = sqcs.size();
    }
    return index;
}

void check_all_sequence(const std::string & sqcs)
{
    for(size_t i = 0; i < sqcs.size(); i++)
    {
        char bracket{};
        bracket = get_close_bracket(sqcs[i]);
        if(sqcs[i] == SPACE)
            continue;
        if(bracket != ERROR)
            i = is_bracket_paired(sqcs, i + 1, bracket);
        if(i >= sqcs.size() || bracket == ERROR)
        {
            std::cout << "no\n";
            return;
        }
    }
    std::cout << "yes\n";
}

int main(int argc, char **argv)
{
    std::string sqcs{""};
    for(size_t i = 1; i < argc; i++)
    {
        sqcs += std::string(argv[i]);
    }
    check_all_sequence(sqcs);
    return 0;
}