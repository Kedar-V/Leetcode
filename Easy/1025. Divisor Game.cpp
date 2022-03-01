class Solution {
public:  

char toggle_player(char current)
{
    if (current == 'A') {
        return 'B';
    }
    return 'A';
}

bool game_helper(int N, char player)
{
    if(N == 1 && player == 'A')
        return false;
        
    if(N == 1 && player == 'B')
        return true;
    
    vector<int> temp;
    
    for (int i = 1; i < N; i++)
    {
        if (N % i == 0) {
            temp.push_back(i);
            break;
        }
    }
    char turn = toggle_player(player);
    for (auto ptr = temp.begin(); ptr != temp.end(); ptr++)
    {
        if(game_helper(N - *ptr, turn))
            return true;
        return false;
    }
    return false;
}


  bool divisorGame(int N)
  {
      return game_helper(N, 'A');
  }
    
};
