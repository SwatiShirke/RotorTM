from setuptools import find_packages
from setuptools import setup

setup(
    name='rotor_tm_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('rotor_tm_msgs', 'rotor_tm_msgs.*')),
)
