import unittest

from dcp.problems.graph.build_order import Builder1

class Test_Builder1(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        
        builder = Builder1(None, None)

        assert builder != None
        assert builder.build_all() == None

    def test_case2(self):

        projects = ['a', 'b', 'c', 'd', 'e', 'f']
        dependencies = [('a', 'd'), ('f', 'b'), ('b', 'd'), ('f', 'a'), ('d', 'c')]

        builder = Builder1(projects, dependencies)

        success = None

        try:

            build_list = builder.build_all()
                            
            # test build all projects
            for built in build_list:
                projects.remove(built)
            
            success = True

        except Builder1.CircularReferenceError:
            success = False
        
        assert success == True
        assert projects == []

    def test_case3(self):

        # circular build defintion

        projects = ['a', 'b', 'c', 'd', 'e', 'f']
        dependencies = [('a', 'd'), ('f', 'b'), ('b', 'd'), ('f', 'a'), ('d', 'c'), ('c', 'f')]

        builder = Builder1(projects, dependencies)

        success = None

        try:
            # test build all projects
            build_list = builder.build_all()

            for built in build_list:
                projects.remove(built)
            
            success = True
        except Builder1.CircularReferenceError:
            success = False

        assert success == False

    def test_case4(self):

        # circular build defintion

        projects = ['a', 'b', 'c', 'd', 'e', 'f', 'g']
        dependencies = [('a', 'd'), ('f', 'b'), ('b', 'd'), ('f', 'a'), ('d', 'c'), ('c', 'f'), ('b', 'g')]

        builder = Builder1(projects, dependencies)

        success = None

        try:
            build_list = builder.build_all()

            # test build all projects
            for built in build_list:
                projects.remove(built)

            success = True
        except Builder1.CircularReferenceError:
            success = False

        assert success == False

    def test_case5(self):

        # circular build defintion

        projects = ['a', 'b', 'c', 'd', 'e', 'f', 'h']
        dependencies = [('a', 'e'), ('b', 'a'), ('c', 'a'), ('f', 'a'), ('f', 'c'), ('f', 'b'), ('b', 'e'), ('d', 'g'), ('b', 'h'), ['e', 'f']]

        builder = Builder1(projects, dependencies)

        success = False
        # test build all projects
        try:
            
            build_list = builder.build_all()

            for built in build_list:
                projects.remove(built)

            success = True
        
        except Builder1.CircularReferenceError:
            success = False
        
        assert success == False
        assert projects != []

    def test_case5(self):

        # non-circular build defintion

        projects = ['a', 'b', 'c', 'd', 'e', 'f', 'g']
        dependencies = [('a', 'e'), ('b', 'a'), ('c', 'a'), ('f', 'a'), ('f', 'c'), ('f', 'b'), ('b', 'e'), ('d', 'g')]

        builder = Builder1(projects, dependencies)

        success = False
        # test build all projects
        try:
            
            build_list = builder.build_all()

            for built in build_list:
                projects.remove(built)

            success = True
        
        except Builder1.CircularReferenceError:
            success = False
        
        assert success == True
        assert projects == []