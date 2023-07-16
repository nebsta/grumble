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
    print(self.build_folder)
  
    tools.files.copy(self, pattern="*.a", src=self.build_folder, dst=self.package_folder)
    tools.files.copy(self, pattern="*.hpp", src=self.build_folder, dst=os.path.join(self.package_folder, "include"))
      
