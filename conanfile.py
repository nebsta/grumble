from conan import ConanFile, tools
from conans.model.version import Version

import os

class Generator(ConanFile):
  name = "grumble"
  version = "1.0.0"
  settings = "os", "build_type", "arch"
  description = "2D engine built in C++"
  author = "Benjamin Wallis"
  requires = ["glm/cci.20230113", "nlohmann_json/3.11.2", "freetype/2.11.1", "libpng/1.6.40"]
  generators = "XcodeDeps"

  def package(self):
    tools.files.copy(self, pattern="*.a", src=self.source_folder, dst=self.package_folder)
    tools.files.copy(self, pattern="*.hpp", src=self.source_folder, dst=os.path.join(self.package_folder, "include"))

  def package_info(self):
    self.cpp_info.libs = ["grumble"]
    self.cpp_info.includedirs = ["include"]
    self.cpp_info.libdirs = ["lib"]
