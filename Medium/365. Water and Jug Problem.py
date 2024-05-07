class Solution:
    def canMeasureWater(self, x: int, y: int, target: int) -> bool:
        self.x = x
        self.y = y
        self.map = set()

        def helper(jug1, jug2):
            key = (jug1, jug2)
            if key in self.map:
                return False
            self.map.add(key)

            if jug1 + jug2 == target:
                return True
            
            empty = helper(jug1, 0) or helper(0, jug2)
            if empty:
                return True

            fill = helper(self.x, jug2) or helper(jug1, self.y) or helper(self.x, self.y)
            if fill:
                return True

            transfer1 = (helper(jug1 + jug2, 0) if jug1 + jug2 <= self.x else helper(self.x, (jug1 + jug2) - self.x)) 
            if transfer1:
                return True

            transfer2 = (helper(0, jug1 + jug2) if jug1 + jug2 <= self.y else helper((jug1 + jug2) - self.y, self.y)) 
            if transfer2:
                return True
            
            return False

        return helper(0, self.y) or helper(self.x, 0)
