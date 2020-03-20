'''Animal Shelter.

An animal shelter, which holds only dogs and cats, operates on a strictly "first in, 
first out" basis. People must adopt either the "oldest" (based on arrival time) of 
all animals in the shelter, or they can select whether they would prefer a dog or a cat 
(and will receive the oldest animal of that type). They cannot select which specific 
animal they would like. 

Create the data structures to maintain this system and implement operations such as:

enqueue, dequeueAny, dequeueDog and dequeue cat.

You may use the built-in LinkedList data structure.
'''

from enum import Enum

class Species(Enum):
    Dog = 1
    Cat = 2

class Node():

    def __init__(self, data, next=None):
        self.data = data
        self.next = None

class Animal():

    def __init__(self, name, species):
        self.name = name
        self.species = species
      
class AnimalShelter():

    def __init__(self):
        self.head, self.tail = None, None
 
    def enqueue(self, animal):
        
        node = Node(animal)

        if self.head == None:
            self.head, self.tail = node, node
        else:
            self.tail.next = node
            self.tail = node

    def dequeue_any(self):
        
        if self.head == None: return None

        adopted = self.head.data
        self.head = self.head.next
        return adopted

    def __dequeue_species(self, species):
        
        current, prev = self.head, None

        while current != None and current.data.species != species:
            prev =  current
            current = current.next

        if current == None: return None

        adopted = current.data

        if prev != None:
            prev.next = current.next
        else:
            self.head = current.next

        return adopted

    def dequeue_dog(self):
        return self.__dequeue_species(Species.Dog)

    def dequeue_cat(self):
        return self.__dequeue_species(Species.Cat)

shelter = AnimalShelter()

assert shelter.dequeue_any() == None

shelter.enqueue(Animal("Burt", Species.Dog))
shelter.enqueue(Animal("Ernie", Species.Dog))
shelter.enqueue(Animal("Angus", Species.Dog))
shelter.enqueue(Animal("Garfield", Species.Cat))
shelter.enqueue(Animal("Whiskers", Species.Cat))
shelter.enqueue(Animal("Grumpy", Species.Cat))

adopt1 = shelter.dequeue_cat()
assert adopt1.name == "Garfield" and adopt1.species == Species.Cat

adopt2 = shelter.dequeue_cat()
assert adopt2.name == "Whiskers" and adopt2.species == Species.Cat

adopt3 = shelter.dequeue_cat()
assert adopt3.name == "Grumpy" and adopt3.species == Species.Cat

assert shelter.dequeue_cat() == None

adopt4 = shelter.dequeue_dog()
assert adopt4.name == "Burt" and adopt4.species == Species.Dog

adopt5 = shelter.dequeue_dog()
assert adopt5.name == "Ernie" and adopt5.species == Species.Dog

adopt6 = shelter.dequeue_dog()
assert adopt6.name == "Angus" and adopt6.species == Species.Dog

assert shelter.dequeue_cat() == None
assert shelter.dequeue_dog() == None
assert shelter.dequeue_any() == None
