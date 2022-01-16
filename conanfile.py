from conans import ConanFile, tools


class HelloConan(ConanFile):
    name = "grumble"
    version = "1.0.0"
    settings = "os", "compiler", "build_type", "arch"
    description = "2D engine built in C++"
    url = "None"
    license = "None"
    author = "Benjamin Wallis"
    topics = None

    def package(self):
        self.copy("*.a", "lib", "lib")
        self.copy("*.hpp", "lib/incude", "grumble")

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
