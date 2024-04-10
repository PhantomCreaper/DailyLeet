# 950. reveal cards in increasing order
class Solution(object):
    def deckRevealedIncreasing(self, deck):
        """
        :type deck: List[int]
        :rtype: List[int]
        """
        queue = deque(range(len(deck)))
        res = [0]*len(deck)
        deck = sorted(deck)
        print(deck)
        for q in deck:
            i = queue.popleft()
            res[i] = q 
            if queue:
                queue.append(queue.popleft())
        return res
            

