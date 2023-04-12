/*
Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level,
and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'.

For this problem, any other format of periods such as '...' are treated as file/directory names.

The canonical path should have the following format:

    1. The path starts with a single slash '/'.
    2. Any two directories are separated by a single slash '/'.
    3. The path does not end with a trailing '/'.
    4. The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')

Return the simplified canonical path.


Example 1:
Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.

Example 2:
Input: path = "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

Example 3:
Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.

Constraints:
    1 <= path.length <= 3000
    path consists of English letters, digits, period '.', slash '/' or '_'.
    path is a valid absolute Unix path.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> st;
        stringstream ss(path);
        string dir;

        while (getline(ss, dir, '/'))
        {
            if (dir.empty() || dir == ".")
                continue;
            else if (dir == "..")
            {
                if (!st.empty())
                    st.pop();
            }
            else
                st.push(dir);
        }

        string res;
        while (!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }

        return res.empty() ? "/" : res;
    }
};

class Solution_without_stack
{
public:
    string simplifyPath(string path)
    {
        vector<string> dirOrFiles;
        stringstream ss(path);
        string dirOrFile;
        while (getline(ss, dirOrFile, '/'))
        {
            if (!dirOrFiles.empty() && dirOrFile == "..")
            {
                dirOrFiles.pop_back();
            }
            else if (dirOrFile != "." && dirOrFile != "" && dirOrFile != "..")
            {
                dirOrFiles.push_back(dirOrFile);
            }
        }
        string simplified_path = "";
        for (string dirOrFile : dirOrFiles)
        {
            simplified_path += "/" + dirOrFile;
        }
        return simplified_path.empty() ? "/" : simplified_path;
    }
};