from setuptools import setup

setup(
   name='dcp',
   version='1.0',
   description='daily coding problem',
   author='Brandon Moretz',
   author_email='bmoretz@ionicsolutions.net',
   packages=['dcp'],  #same as name
   install_requires=['wheel', 'bar', 'greek'],
)