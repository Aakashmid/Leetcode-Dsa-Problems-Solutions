#include <iostream>
#include <vector>
#include <string>
using namespace std;


// Function to concatenate words with a specified delimiter
string concatenate_words(vector<string> line_words, string del)
{
    string ans = "";
    for (int i = 0; i < line_words.size(); i++)
    {
        if (i < line_words.size() - 1)
        {
            ans += line_words[i] + del;
        }
        else
        {
            ans += line_words[i];
        }
    }
    return ans;
}


vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    vector<string> res;
    vector<string> line; // line words
    int length = 0;      // total length of words in line

    int i = 0;
    while (i < words.size())
    {
        // line is completed
        if (length + line.size() + words[i].length() > maxWidth)
        {
            int extra_spaces = maxWidth - length;
            int spaces = extra_spaces / max(1, static_cast<int>(line.size()) - 1); // spaces to put between words  , using max to avoid 0 denominator
            int remainder = extra_spaces % max(1, static_cast<int>(line.size()) - 1);

            for (int j = 0; j < max(1, static_cast<int>(line.size()) - 1); j++)
            {
                line[j].append(spaces, ' ');
                if (remainder > 0)
                {
                    line[j] += ' ';
                    remainder--;
                }
            }

            res.push_back(concatenate_words(line, ""));
            line.clear();
            length = 0;
        }

        // add word to line

        line.push_back(words[i]);
        length += words[i].length();
        i++;
    }

    // handling last line
    string last_line = concatenate_words(line, " ");
    int extra_spaces = maxWidth - last_line.length();
    for (int j = 0; j < extra_spaces; j++)
    {
        last_line += " ";
    }
    res.push_back(last_line);
    return res;
}

int main()
{
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    vector<string> justified_text = fullJustify(words, maxWidth);

    for (const string &line : justified_text)
    {
        cout << "\"" << line << "\"" << endl;
    }

    return 0;
}