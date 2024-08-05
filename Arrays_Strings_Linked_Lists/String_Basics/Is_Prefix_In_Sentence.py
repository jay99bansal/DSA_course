class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        
        sentence_list = sentence.split(" ")

        for idx,sent in enumerate(sentence_list):
            if sent.startswith(searchWord):
                return idx + 1
        
        return -1
    


if __name__ == "__main__":

    sentence = "i love eating burger"
    searchWord = "burg"

    answer1 = Solution().isPrefixOfWord(sentence=sentence,searchWord=searchWord)
    print(answer1)