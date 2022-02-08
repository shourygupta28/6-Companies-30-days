class Solution
{
public:
    void DFS_search(int i, int r, int c, bool &found, vector<vector<char>> &board, string word)
    {

        if (i == word.length())
        {
            found = true;
            return;
        }

        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[i])
            return;

        board[r][c] = 'X';

        DFS_search(i + 1, r + 1, c, found, board, word);
        DFS_search(i + 1, r - 1, c, found, board, word);
        DFS_search(i + 1, r, c + 1, found, board, word);
        DFS_search(i + 1, r, c - 1, found, board, word);

        board[r][c] = word[i];
    }

    bool isWordExist(vector<vector<char>> &board, string word)
    {
        int r = board.size(), c = board[0].size();
        bool found = false;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (board[i][j] == word[0])
                {
                    DFS_search(0, i, j, found, board, word);
                }
            }
        }
        return found;
    }
};