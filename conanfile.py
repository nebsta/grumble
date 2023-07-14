from conan import ConanFile, tools

class HelloConan(ConanFile):
    name = "grumble"
    version = "1.0.0"
    settings = "os", "compiler", "build_type", "arch"
    description = "2D engine built in C++"
    url = "None"
    license = "None"
    author = "Benjamin Wallis"
    topics = None
    requires = ["glm/0.9.9.8", "nlohmann_json/3.10.5"]
    generators = "xcode"

    def package(self):
        self.copy("*.a", "lib", "lib")
        self.copy("*.hpp", "include/grumble", "grumble")

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
