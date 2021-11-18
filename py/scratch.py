from collections import defaultdict
import string

class Trie:

    class Node:
        
        _letter = None
        _count = None
        _children = None

        def __init__(self, letter):
            self._letter = letter
            self._children = [None] * 36
            self._count = 0

        def increment(self):
            self._count = self._count + 1

        def decrement(self):
            self._count = self._count - 1

        def __len__(self) -> int:
            return self._count

        def __getitem__(self, letter : str) -> 'Trie.Node':
            idx = Trie._get_index(letter)
            return self._children[idx]

        def __setitem__(self, letter : str, _) -> None:
            idx = Trie._get_index(letter)

            if self._children[idx] is None:
                self._children[idx] = Trie.Node(letter)

            child:Trie.Node
            child = self._children[idx]
            child.increment()

        def __delitem__(self, letter : str) -> None:
            idx = Trie._get_index(letter)

            child:Trie.Node
            child = self._children[idx]
            
            if child is not None:
                child.decrement()

                if len(child) == 0:
                    self._children[idx] = None
    
    _root = None
    _lookup = defaultdict(int)

    def __init__(self):
        self._root = Trie.Node(None)

        for index, char in enumerate(string.ascii_lowercase + string.digits):
            self._lookup[char] = index        

    @classmethod
    def _get_index(cls, letter : str) -> int:
        return cls._lookup[letter]
        
    def insert(self, word: str) -> None:
        
        node = self._root

        for _, chr in enumerate(word):
            child = node[chr]

            if child is None:
                node[chr] = chr
            else:
                child.increment()

            node = node[chr]

    def _get_matches(self, word : str,
                    partial : bool = False) -> int:

        node = self._root
        match = ''

        for _, char in enumerate(word):

            if node[char] is None:
                break

            if partial and len(match) == len(word):
                break

            match += char
            node = node[char]

        return len(node) if word == match else 0

    def countWordsEqualTo(self, word: str) -> int:
        return self._get_matches(word)

    def countWordsStartingWith(self, prefix: str) -> int:
        return self._get_matches(prefix, True)

    def erase(self, word: str) -> None:

        node = self._root
        to_remove = []

        for _, char in enumerate(word):

            if node[char] is None:
                break

            to_remove.append((node, char))
            node = node[char]

        while len(to_remove) > 0:
            node, char = to_remove.pop()
            del node[char]

trie = Trie()

trie.insert("a01b2")

actual = trie.countWordsStartingWith("a0")
print(actual)

actual = trie.countWordsStartingWith("gy")
print(actual)

trie.insert("gyu")

trie.erase("gyu")

trie.insert("gyu")

actual = trie.countWordsEqualTo("gyu")
print(actual)