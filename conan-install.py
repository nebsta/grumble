#!/usr/bin/python3

import subprocess

subprocess.Popen(["conan", "install", "conanfile.py", "-s", "build_type=Debug", "--output-folder", "conan", "--build", "missing"])
