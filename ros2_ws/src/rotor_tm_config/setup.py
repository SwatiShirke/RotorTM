from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'rotor_tm_config'

# Helper function to gather all YAML files and retain directory structure
def package_data_files(source, destination):
    files = []
    for file in glob(os.path.join(source, '**', '*.yaml'), recursive=True):
        # Re-create the directory structure in the destination path
        dest_path = os.path.join(destination, os.path.relpath(file, source))
        files.append((os.path.dirname(dest_path), [file]))
    return files

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ] + package_data_files('config', os.path.join('share', package_name, 'config')),
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='swati',
    maintainer_email='swatishirke.shirke88@gmail.com',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [],
    },
    include_package_data=True,
)
