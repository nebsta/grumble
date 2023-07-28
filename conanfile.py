from conan import ConanFile, tools
from conans.model.version import Version

import os

class Generator(ConanFile):
  name = "grumble"
  version = "1.0.0"
  settings = "os", "build_type", "arch"
  description = "2D engine built in C++"
  author = "Benjamin Wallis"
  requires = ["glm/cci.20230113", "nlohmann_json/3.11.2"]
  generators = "XcodeDeps"

  def package(self):
    tools.files.copy(self, pattern="*.a", src=self.source_folder, dst=self.package_folder)
    tools.files.copy(self, pattern="*.hpp", src=self.source_folder, dst=os.path.join(self.package_folder, "include"))
    tools.files.copy(self, pattern="*.h", src=os.path.join(self.source_folder, "freetype/include"), dst=os.path.join(self.package_folder, "freetype/include"))

  def package_info(self):
    self.cpp_info.libs = ["grumble", "freetype", "png16", "bz2", "z"]
    self.cpp_info.includedirs = ["include", "freetype/include"]
    self.cpp_info.libdirs = ["lib", "freetype/lib"]
