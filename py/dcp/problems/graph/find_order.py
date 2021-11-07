'''Topological sort.

We are given a hasmap associating each courseId key with a list of courseIds values, which tells us that the prerequisites of courseId
are course Ids. Return a sorted ordering of courses such that we can complete the curriculum.

Return null if there is no such ordering.

For example, given the following prerequisites:

{
    'CSC300' : ['CSC100', 'CSC200'],
    'CSC200' : ['CSC100'],
    'CSC100' : []
}

You should return ['CSC100', 'CSC200', 'CSC300'].
'''

from collections import deque, defaultdict

def find_order1(courses_to_prereqs : dict):

    # Copy list values into a set for faster removal
    course_to_prereqs = {c : set(p) for c, p in courses_to_prereqs.items()}

    # Start off our list with all courses without prerequisites.
    todo = deque([c for c, p in course_to_prereqs.items() if not p])

    # Create a new data structure to map prereqs to successor courses.
    prereq_to_courses = defaultdict(list)

    for course, prereqs in course_to_prereqs.items():
        for prereq in prereqs:
            prereq_to_courses[prereq].append(course)

    result = []

    while todo:
        prereq = todo.popleft()
        result.append(prereq)

        # Remove this prereq from all successor courses.
        # If any course now does not have any prereqs, add it to todo.

        for c in prereq_to_courses[prereq]:
            course_to_prereqs[c].remove(prereq)

            if not course_to_prereqs[c]:
                todo.append(c)

    # Circular dependency
    if len(result) < len(course_to_prereqs):
        return None

    return result