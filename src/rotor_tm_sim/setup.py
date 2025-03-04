from setuptools import find_packages, setup
import os
from glob import glob
package_name = 'rotor_tm_sim'

def package_data_files(source, destination):
    files = []
    for file in glob(os.path.join(source, '**', '*.[sS][tT][lL]'), recursive=True):
        # Re-create the directory structure in the destination path
        dest_path = os.path.join(destination, os.path.relpath(file, source))
        files.append((os.path.dirname(dest_path), [file]))
    return files



setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*.[pxy][yma]*')))
        ] + package_data_files('mesh', os.path.join('share', package_name, 'mesh')) ,
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='swati',
    maintainer_email='swatishirke.shirke88@gmail.com',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'sim_node = rotor_tm_sim.runsim:main',
            'data_saver_node = rotor_tm_sim.data_saver_node:main'

        ],
    },
)
