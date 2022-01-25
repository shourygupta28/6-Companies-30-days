class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        unordered_set<string> s;
        
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                int num= mat[i][j];
                
                if( num!=0 )
                {    
                    string row= to_string(num) + "in row"+ to_string(i);
                    string col= to_string(num) + "in cloumn" + to_string(j);
                    string grid= to_string(num) + "in (x,y)=" + to_string(i/3) + " " + to_string(j/3);
                    
                    if( s.find(row)!=s.end() || s.find(col)!=s.end() || s.find(grid)!=s.end())
                            return 0;
                    
                    s.insert(row);
                    s.insert(col);
                    s.insert(grid);
                }
            }
        }
        return 1;
    }
};