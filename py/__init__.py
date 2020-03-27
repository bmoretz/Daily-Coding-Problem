'''Build Order.

You are given a list of projects and a list of dependencies (which is
a list of pairs of projects, where the second project is dependent on
the first project). All of a project's dependencies must be built before
the project is. Find a build order that will allow the projects to be built. If
there is no valid build order, return an error.

EXAMPLE

Input:
    projects: a, b, c, d, e, f
    dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)
Output:
    f, e, a, b, d, c
'''

class Builder1():

    class CircularReferenceError(ReferenceError):

        def __init__(self):
            pass

    def __init__(self, projects, dependencies):
        self.projects = {}

        if projects is None: return

        for proj in projects:
            self.__add_project(proj)

        if dependencies is None: return

        for dep in dependencies:
            self.__add_dependency(dep[0], dep[1])

    def __add_project(self, project):
        self.projects[project] = []

    def __add_dependency(self, project, dep):
        self.projects[project].append(dep)

    def __get_dependencies(self, project, prior=[], pending=[]):
        dependencies, subprojects = [project], self.projects[project]
        
        if subprojects != []:
            for sub in subprojects:
                if sub in pending:
                    raise self.CircularReferenceError()

                if sub not in prior:
                    dependencies += self.__get_dependencies(sub, prior, pending)

        return dependencies

    def build_project(self, project):
        
        dependencies = [project]
        built = []

        for proj in self.projects[project]:
            dep = self.__get_dependencies(proj, built, dependencies)

            dependencies += dep

            built.append(dependencies)
            # reset the build list after completion
            dependencies = [project]

        return dependencies

    def dep_list(self):
        dep_list = {}

        for proj in projects:
            dep_list[proj] = len(self.build_project(proj)) - 1

        return dep_list

    def build_all(self):
        
        to_build = list(self.projects.keys())

        if to_build == None: return None

        built = []

        while len(to_build) > 0:

            current = to_build.pop()

            dependencies = self.build_project(current)

            for dep in dependencies:

                if dep in to_build: 
                    to_build.remove(dep)

                if dep not in built:
                    built = built + [dep]

        return built

builder = Builder1(
    ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'], 
    [('a', 'e'), ('b', 'a'), ('c', 'a'), ('f', 'a'), ('f', 'c'), ('f', 'b'), ('b', 'e'), ('d', 'g'), ('b', 'h'), ('e', 'f')])

# build_order = builder.build_all()

d = builder.build_project('f')

print(d)