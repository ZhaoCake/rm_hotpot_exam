from setuptools import find_packages
from setuptools import setup

setup(
    name='mineral_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('mineral_interfaces', 'mineral_interfaces.*')),
)
