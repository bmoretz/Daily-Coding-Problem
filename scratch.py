from collections import defaultdict

from problems.graph import IGraph, find_path
from problems.graph.adj_list_graph import ALGraph
from problems.graph.adj_mat_graph import AMGraph

''' Create stepword chain.

Given a start word, an end word, and a dictionary of valid words, find the shortest transformation sequence from start to end
such that only one letter is changed at each step of the sequence, and each transformed word exists in the dictionary. If
there is no possible transformation, return null. Each word in the dictionary has the same length as start and end and is lowercase.

For example, 

given start = "dog", end = "cat", and dictionary = {"dot", "dop", "dat", "cat"},

return ["dog", "dot", "dat", "cat"]

given start = "dog", end = "cat", and dictionary = {"dot", "tod", "dat", "dar"},
return null as there is no possible transformation from "dog" to "cat".
'''

start, end = "dog", "cat"
words = {"dot", "dop", "dat", "cat"}

''' ***************** '''

def word_ladder1(start, end, words):

    all_words = set(words) | set([start, end])

    def are_similar(word1, word2):
        ''' return true if words are seperated by only 1 character '''
        n1, n2 = len(word1), len(word2)

        if n1 != n2: 
            return False

        differences = 0

        for index in range(n1):
            if word1[index] != word2[index]:
                differences += 1

        return differences <= 1

    def gen_links(words):
        ''' returns dictionary of words seperated by 1 char or less '''
        links = defaultdict(list)

        for word1 in all_words:
            for word2 in all_words:

                if word1 == word2: 
                    continue

                if are_similar(word1, word2):
                    links[word1].append(word2)
        return links

    links = gen_links(all_words)

    graph = ALGraph(links)

    path = find_path(graph, start, end)

    return path

print(word_ladder1(start, end, words))