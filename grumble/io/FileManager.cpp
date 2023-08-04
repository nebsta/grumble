//
//  FileManager.cpp
//  grumble
//
//  Created by Benjamin Wallis on 19/01/2022.
//

#include "FileManager.hpp"

namespace grumble {
  FileManager::FileManager(std::string rootpath) : _rootPath(rootpath) {
    
  }

  FileManager::~FileManager() {
    
  }

  std::string FileManager::loadFile(std::filesystem::path filename) {
    std::filesystem::path path = buildFilePath(filename);
    if (!std::filesystem::exists(path)) {
      logError("File at path " + path.string() + " doesn't exist.");
      return "";
    }
    
    std::ifstream file(path);
    std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return str;
  }

  std::vector<char> FileManager::loadFileRaw(std::filesystem::path filename) {
    std::filesystem::path path = buildFilePath(filename);
    if (!std::filesystem::exists(path)) {
      logError("File at path " + path.string() + " doesn't exist.");
      return std::vector<char>();
    }
    
    std::ifstream file(path, std::ios_base::binary);
    std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return buffer;
  }

  std::shared_ptr<ImageFile> FileManager::loadPNG(std::filesystem::path filename) {
    logInfo("Attempting to load png image: " + filename.string());
    
    std::filesystem::path path = buildFilePath(filename);
    if (!std::filesystem::exists(path)) {
      logError("File at path " + path.string() + " doesn't exist.");
      return nullptr;
    }
    
    FILE *fp = fopen(path.c_str(), "rb");
    png_structp pngPtr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, FileManager::pngError, FileManager::pngWarning);
    if (!pngPtr) {
      logError("Couldn't initialise png read struct");
      fclose(fp);
      return nullptr;
    }

    png_infop infoPtr = png_create_info_struct(pngPtr);
    if (!infoPtr) {
      logError("Couldn't initialise png info struct");
      png_destroy_read_struct(&pngPtr, (png_infopp)0, (png_infopp)0);
      fclose(fp);
      return nullptr;
    }
    
    png_init_io(pngPtr, fp);
    png_read_info(pngPtr, infoPtr);
    
    png_uint_32 imgWidth =  png_get_image_width(pngPtr, infoPtr);
    png_uint_32 imgHeight = png_get_image_height(pngPtr, infoPtr);
//    png_uint_32 bitDepth = png_get_bit_depth(pngPtr, infoPtr);
//    png_uint_32 channels = png_get_channels(pngPtr, infoPtr);
//    png_uint_32 color_type = png_get_color_type(pngPtr, infoPtr);
    
//    logInfo("Image Size: " + std::to_string(imgWidth) + ", " + std::to_string(imgHeight));
//    logInfo("bitDepth: " + std::to_string(bitDepth));
//    logInfo("channels: " + std::to_string(channels));
//    logInfo("color_type: " + std::to_string(color_type));
    
    size_t rowSize = png_get_rowbytes(pngPtr, infoPtr);
    auto arrayLength = imgHeight * rowSize;
    png_byte* rowPtrs = new png_byte[arrayLength];
    
    for (int i = 0; i < imgHeight; i++) {
      long index = (arrayLength - rowSize) - rowSize * i;
      png_read_row(pngPtr, &rowPtrs[index], NULL);
    }
    png_read_end(pngPtr, infoPtr);
    
    fclose(fp);
    png_destroy_read_struct(&pngPtr, &infoPtr, NULL);
    return std::make_shared<ImageFile>(imgWidth, imgHeight, rowSize, rowPtrs);
  }

  void FileManager::pngError(png_structp png_ptr, png_const_charp error_msg) {
    Logger::log("PNG load Error: " + std::string(error_msg), LogLevel::error, LogCategory::io);
  }

  void FileManager::pngWarning(png_structp png_ptr, png_const_charp warning_msg) {
    Logger::log("PNG load Warning: " + std::string(warning_msg), LogLevel::warn, LogCategory::io);
  }

  void FileManager::readPNGData(png_structp pngPtr, png_bytep data, png_size_t length) {
     png_voidp a = png_get_io_ptr(pngPtr);
     ((std::istream*)a)->read((char*)data, length);
  }

  nlohmann::json FileManager::loadJson(std::filesystem::path filename) {
    std::string raw = loadFile(filename);
    return nlohmann::json::parse(raw);
  }

  std::filesystem::path FileManager::buildFilePath(std::filesystem::path filename) {
    return _rootPath / filename;
  }

  LogCategory FileManager::logCategory() {
    return LogCategory::io;
  }
}
