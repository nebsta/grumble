from conan import ConanFile, tools
from conans.model.version import Version

import os

class Generator(ConanFile):
  name = "grumble"
  version = "1.0.0"
  settings = "os", "build_type", "arch"
  description = "2D engine built in C++"
  author = "Benjamin Wallis"
  requires = ["freetype/2.11.1", "libpng/1.6.42", "fmt/10.0.0"]
  generators = ["CMakeDeps", "CMakeToolchain"]

  def requirements(self):
     self.requires("glm/cci.20230113", transitive_headers=True)
     self.requires("nlohmann_json/3.11.2", transitive_headers=True)
  def build_reqirements(self):
     self.tool_requires("glm/cci.20230113")
     self.tool_requires("nlohmann_json/3.11.2")

  def package(self):
    source_build_path = os.path.join(self.source_folder, "build")
    source_path = os.path.join(self.source_folder, "src")
    package_lib_path = os.path.join(self.package_folder, "lib")
    package_include_path = os.path.join(self.package_folder, "include/grumble")

    tools.files.copy(self, pattern="*.a", src=source_build_path, dst=package_lib_path)
    tools.files.copy(self, pattern="*.hpp", src=source_path, dst=package_include_path)

  def package_info(self):
    self.cpp_info.libs = ["grumble"]
    self.cpp_info.includedirs = ["include"]
    self.cpp_info.libdirs = ["lib"]
