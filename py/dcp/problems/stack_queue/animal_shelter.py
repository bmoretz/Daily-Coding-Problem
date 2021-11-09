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

''' common types for animal shelters. '''

from enum import Enum
from datetime import datetime

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
        self.arrival_time = datetime.now()

''' Solution 1:

Use a single linked-list to maintain all animals.

pros: single easily extendable for new animal species.
cons: the species specific dequeue methods are slightly less efficient than the two-queue approach.
'''
class AnimalShelter1():

    def __init__(self):
        self.head, self.tail = None, None
 
    def enqueue(self, animal : Animal):
        
        if animal == None: return None

        if not isinstance(animal, Animal):
            raise TypeError(f'Can only accept types of Animal, not {type(animal)}')

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


''' Solution 2:

Implement an animal queue class, and composition pattern in the shelter such that
a shelter has N queues, where N is the number of species.

pros: efficient and maintable. Could be improved with a list of queues to be more extendable.
cons: the dequeue_any method could be cleaner.
'''

class AnimalQueue():

    def __init__(self):
        self.head, tail = None, None

    def enqueue(self, animal : Animal):
        node = Node(animal)

        if self.head == None:
            self.head, self.tail = node, node
        else:
            self.tail.next = node
            self.tail = node

    def dequeue(self):
        if self.head == None: return None

        item = self.head.data
        self.head = self.head.next
        return item
    
    def peek(self):
        return self.head.data if self.head != None else None

class AnimalShelter2():

    def __init__(self):
        self.cats, self.dogs = AnimalQueue(), AnimalQueue()
 
    def enqueue(self, animal : Animal):
        
        if animal == None: return

        if not isinstance(animal, Animal):
            raise TypeError(f'Can only accept types of Animal, not {type(animal)}')

        if animal.species == Species.Dog:
            self.dogs.enqueue(animal) 
        elif animal.species == Species.Cat:
            self.cats.enqueue(animal)

    def dequeue_any(self):
        
        if self.dogs.peek() == None and self.cats.peek() == None: return None

        queue = None

        if self.dogs.peek() != None and self.cats.peek() == None:
            queue = self.dogs
        elif self.dogs.peek() == None and self.cats.peek() != None:
            queue = self.cats
        elif self.dogs.peek() != None and self.cats.peek() != None:
            queue = self.dogs if self.dogs.peek().arrival_time < self.cats.peek().arrival_time else self.cats

        return queue.dequeue()

    def dequeue_dog(self):
        return self.dogs.dequeue()

    def dequeue_cat(self):
        return self.cats.dequeue()