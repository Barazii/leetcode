class Solution
{
public:
    bool isValid(string s)
    {
        // checks
        if (find(s.begin(), s.end(), ')') != s.end() or
            find(s.begin(), s.end(), '(') != s.end())
        {
            int oo = count(s.begin(), s.end(), '(');
            int co = count(s.begin(), s.end(), ')');
            if (oo != co)
                return false;

            vector<int> oi{};
            vector<int> ci{};
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == '(')
                    oi.push_back(i);
                if (s[i] == ')')
                    ci.push_back(i);
            }
            // check order of brackets (compare indecies)
            for (int i = 0; i < oi.size(); i++)
                if (oi[i] >= ci[i])
                    return false;
        }
        if (find(s.begin(), s.end(), ']') != s.end() or
            find(s.begin(), s.end(), '[') != s.end())
        {
            int oo = count(s.begin(), s.end(), '[');
            int co = count(s.begin(), s.end(), ']');
            if (oo != co)
                return false;

            vector<int> oi{};
            vector<int> ci{};
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == '[')
                    oi.push_back(i);
                if (s[i] == ']')
                    ci.push_back(i);
            }
            // check order of brackets (compare indecies)
            for (int i = 0; i < oi.size(); i++)
                if (oi[i] >= ci[i])
                    return false;
        }
        if (find(s.begin(), s.end(), '}') != s.end() or
            find(s.begin(), s.end(), '{') != s.end())
        {
            int oo = count(s.begin(), s.end(), '{');
            int co = count(s.begin(), s.end(), '}');
            if (oo != co)
                return false;

            vector<int> oi{};
            vector<int> ci{};
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == '{')
                    oi.push_back(i);
                if (s[i] == '}')
                    ci.push_back(i);
            }
            // check order of brackets (compare indecies)
            for (int i = 0; i < oi.size(); i++)
                if (oi[i] >= ci[i])
                    return false;
        }

        vector<int> open_paranthesis{};
        vector<int> open_square_brackets{};
        vector<int> open_braces{};
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' or s[i] == ')')
            {
                if (s[i] == '(')
                    open_paranthesis.push_back(i);
                if (s[i] == ')')
                {
                    if (open_square_brackets.empty() and open_braces.empty())
                        open_paranthesis.pop_back();
                    else
                    {
                        if (!open_square_brackets.empty())
                        {
                            for (int j : open_square_brackets)
                            {
                                if (open_paranthesis.back() < j and j < i)
                                    return false;
                                else
                                    continue;
                            }
                            // open_paranthesis.pop_back();
                        }
                        if (!open_braces.empty())
                        {
                            for (int j : open_braces)
                            {
                                if (open_paranthesis.back() < j and j < i)
                                    return false;
                                else
                                    continue;
                            }
                        }
                        open_paranthesis.pop_back();
                    }
                }
            }
            if (s[i] == '{' or s[i] == '}')
            {
                if (s[i] == '{')
                    open_braces.push_back(i);
                if (s[i] == '}')
                {
                    if (open_paranthesis.empty() and
                        open_square_brackets.empty())
                        open_braces.pop_back();
                    else
                    {
                        if (!open_paranthesis.empty())
                        {
                            for (int j : open_paranthesis)
                            {
                                if (open_braces.back() < j and j < i)
                                    return false;
                                else
                                    continue;
                            }
                            // open_braces.pop_back();
                        }
                        if (!open_square_brackets.empty())
                        {
                            for (int j : open_square_brackets)
                            {
                                if (open_braces.back() < j and j < i)
                                    return false;
                                else
                                    continue;
                            }
                        }
                        open_braces.pop_back();
                    }
                }
            }
            if (s[i] == '[' or s[i] == ']')
            {
                if (s[i] == '[')
                    open_square_brackets.push_back(i);
                if (s[i] == ']')
                {
                    if (open_paranthesis.empty() and open_braces.empty())
                        open_square_brackets.pop_back();
                    else
                    {
                        if (!open_paranthesis.empty())
                        {
                            for (int j : open_paranthesis)
                            {
                                if (open_square_brackets.back() < j and j < i)
                                    return false;
                                else
                                    continue;
                            }
                            // open_square_brackets.pop_back();
                        }
                        if (!open_braces.empty())
                        {
                            for (int j : open_braces)
                            {
                                if (open_square_brackets.back() < j and j < i)
                                    return false;
                                else
                                    continue;
                            }
                        }
                        open_square_brackets.pop_back();
                    }
                }
            }
        }
        return true;
    }
};

// 1. Working with arrays of strings makes it hard to use math formula's or algortihms
// that apply on clusters of numbers since we search for distinct characters so we have
// to process those chars independently. (So it's more work.)
// 2. Useful std stuff: std::count(), std::find(), for(char i : std::string), for(int i : std::vector<int>).