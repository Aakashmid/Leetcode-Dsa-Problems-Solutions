
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


/*
Approach for fullJustify function:
1. Initialize result vector and current line vector
2. For each word in input:
   - If adding current word exceeds maxWidth:
     a. Calculate spaces needed between words
     b. Distribute spaces evenly between words
     c. Add extra spaces from left if not equally divisible
     d. Add line to result and reset current line
   - Add current word to line
3. Handle last line specially:
   - Left justify words with single space
   - Pad with extra spaces at end
4. Return result vector
*/

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    vector<string> res;
    vector<string> line; // line words
    int length = 0;      // total length of words in line

    int i = 0;
    while (i < words.size())
    {
        // line is completed
        if (length + line.size() + words[i].length() > maxWidth)  // here line.size()  represents no. of spaces (minimum required)
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

            res.push_back(concatenate_words(line, ""));  // concatenater words function for making a single stirng from line array of string 
            line.clear();
            length = 0;
        }

        // add word to line

        line.push_back(words[i]);
        length += words[i].length();
        i++;
    }

    // handling last line
    string last_line = concatenate_words(line, " ");  // in last line each word is seperated by only single space and all extra space is added to right
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