import os

TEST_DATA_PATH = ['data', 'illuminated']

def get_test_data_path() -> str:

    path_parent = os.path.dirname(os.getcwd())

    return os.path.join(path_parent, *TEST_DATA_PATH)

def get_test_file(problem : str, test_file_name : str) -> str:

    return os.path.join(get_test_data_path(), problem, test_file_name)