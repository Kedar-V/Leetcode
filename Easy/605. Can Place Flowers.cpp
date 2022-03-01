class Solution {
public:
    
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if (flowerbed.size() == 1)
        {
            if (flowerbed[0] == 0)
                return n <= 1;
            return n == 0;
        }
        
        flowerbed.push_back(1);

        int maxPlants = 0;   
        int start = -1;
        
        int end = -1;
        int len = flowerbed.size();
        int count = 0;
        for (int i = 0; i < len; i++)
        {
            // if (flowerbed[0] == 1 and start == -1)
            //     start = i;
            
            if (flowerbed[i] == 1)
            {   
                count++;
                end = i;
                int beds = end-start-1;
                if (beds != 0 and beds%2 == 0 and start != -1 and end != len-1)
                    maxPlants += beds/2 - 1;
                else
                    maxPlants += beds/2;
                start = end;
            }
            
            else
                continue;
        }
        if (count == 1)
        {
            if ((len-1) % 2 != 0)
                maxPlants += 1;
        }
        return maxPlants >= n;
    }
};
