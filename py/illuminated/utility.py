import os

DATA_PATH = ['data', 'illuminated']

def get_test_file(problem : str, test_file_name : str) -> str:

    path_parent = os.path.dirname(os.getcwd())

    return os.path.join(path_parent, *DATA_PATH, problem, test_file_name)