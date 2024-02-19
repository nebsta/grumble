from conan import ConanFile, tools
from conans.model.version import Version

import os

class Generator(ConanFile):
  name = "grumble"
  version = "1.0.0"
  settings = "os", "build_type", "arch"
  description = "2D engine built in C++"
  author = "Benjamin Wallis"
  requires = ["glm/cci.20230113", "nlohmann_json/3.11.2", "freetype/2.11.1", "libpng/1.6.42", "fmt/10.0.0"]
  generators = ["CMakeDeps", "CMakeToolchain"]


